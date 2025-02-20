import network
import socket
from machine import Pin, PWM
import time

led = Pin(6, Pin.OUT)
 
# Set up ESC control on GPIO27 (PWM)
esc = PWM(Pin(1), freq=50)
  # Most ESCs operate at 50Hz

stby = Pin(9, Pin.OUT)
stby.value(1)

# Define motor control pins for the TB6612 module (same as before)
AIN1 = Pin(12, Pin.OUT)
AIN2 = Pin(13, Pin.OUT)
PWMA = PWM(Pin(10))
PWMA.freq(100)#lower this value if the esc buttons control the drive motor

BIN1 = Pin(14, Pin.OUT)
BIN2 = Pin(15, Pin.OUT)
PWMB = PWM(Pin(11))
PWMB.freq(100)

def arm_esc():
    print("Arming ESC...")
    esc.duty_u16(6554)
    time.sleep(2)
    esc.duty_u16(3277)
    #control_esc('brake')  # Arm with brake (1ms pulse)
    for _ in range(6):  # Blink LED 6 times while arming
        led.toggle()
        time.sleep(0.5)
     # Continue holding brake
    time.sleep(1)  # ESC arm delay

# Function to control the ESC
def control_esc(level):
    if level == 'brake':
        duty = 3277  # Brake, 1ms pulse width
    elif level == 'half':
        duty = 4915  # Half-speed, around 1.5ms pulse width
    elif level == 'full':
        duty = 6554  # Full-speed, around 2ms pulse width
    esc.duty_u16(duty)

# Function to control the motors
def control_motor(motor, direction, speed):
    if motor == '1':
        if direction == 'forward':
            AIN1.on()
            AIN2.off()
        elif direction == 'backward':
            AIN1.off()
            AIN2.on()
        elif direction == 'left':
            AIN1.on()
            AIN2.off()
        elif direction == 'right':
            AIN1.off()
            AIN2.on()
        else:
            AIN1.off()
            AIN2.off()
        PWMA.duty_u16(speed)
    
    elif motor == '2':
        if direction == 'forward':
            BIN1.on()
            BIN2.off()
        elif direction == 'backward':
            BIN1.off()
            BIN2.on()
        elif direction == 'left':
            BIN1.off()
            BIN2.on()
        elif direction == 'right':
            BIN1.on()
            BIN2.off()
        else:
            BIN1.off()
            BIN2.off()
        PWMB.duty_u16(speed)

def web_page():
    html = """<!DOCTYPE html>
    <html>
    <head>
    <title>Pico W Gamepad Control</title>
    <style>
    body {
        font-family: Arial, sans-serif;
        text-align: center;
        margin-top: 50px;
        background-color: #f8f9fa; /* Light background for better contrast */
    }
    .button {
        display: inline-block;
        padding: 20px;
        margin: 10px;
        font-size: 20px;
        color: white;
        background-color: #007bff;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        width: 120px; /* Slightly wider buttons */
    }
    .button:hover {
        background-color: #0056b3;
    }
    .container {
        display: flex;
        justify-content: center;
        align-items: flex-start; /* Align items to the start */
    }
    .gamepad {
        display: grid;
        grid-template-columns: repeat(3, 1fr);
        grid-gap: 10px;
        justify-content: center;
        margin-right: 200px; /* Space between gamepad and esc-control */
        width: 250px;
    }
    .esc-control {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        height: 300px; /* Set a fixed height if needed */
    }
    </style>
    <script>
    document.addEventListener('keydown', function(event) {
        switch(event.key) {
            case 'w':
                location.href = '/forward';
                break;
            case 'a':
                location.href = '/left';
                break;
            case 's':
                location.href = '/backward';
                break;
            case 'd':
                location.href = '/right';
                break;
            case ' ':
                location.href = '/stop';
                break;
            case 'f':
                location.href = '/esc?mode=full';
                break;
            case 'h':
                location.href = '/esc?mode=half';
                break;
            case 'b':
                location.href = '/esc?mode=brake';
                break;
        }
    });
    </script>
    </head>
    <body>
    <h1>ESC and Motor Control Gamepad</h1>

    <div class="container">
        <div class="gamepad">
            <div></div>
            <div><button class="button" onclick="location.href='/forward'">Forward</button></div>
            <div></div>
            <div><button class="button" onclick="location.href='/left'">Left</button></div>
            <div><button class="button" onclick="location.href='/stop'">Stop</button></div>
            <div><button class="button" onclick="location.href='/right'">Right</button></div>
            <div></div>
            <div><button class="button" onclick="location.href='/backward'">Backward</button></div>
            <div></div>
        </div>

        <div class="esc-control">
            <button class="button" onclick="location.href='/esc?mode=full'">Full Speed</button>
            <button class="button" onclick="location.href='/esc?mode=half'">Half Speed</button>
            <button class="button" onclick="location.href='/esc?mode=brake'">Brake</button>
        </div>
    </div>

    </body>
    </html>
    """
    return html


# Function to set up Pico W in AP mode
def ap_mode(ssid, password):
    ap = network.WLAN(network.AP_IF)
    ap.config(essid=ssid, password=password)
    ap.active(True)

    while ap.active() == False:
        pass
    print('AP Mode is active, IP Address: ' + ap.ifconfig()[0])

    # Set up the socket server
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(('', 80))
    s.listen(5)

    while True:
        conn, addr = s.accept()
        print('Got a connection from %s' % str(addr))
        request = conn.recv(1024)
        request = str(request)
        print('Content = %s' % request)

        # Control based on request
        if '/forward' in request:
            control_motor('1', 'forward', 32768)
            control_motor('2', 'forward', 32768)
        elif '/backward' in request:
            control_motor('1', 'backward', 32768)
            control_motor('2', 'backward', 32768)
        elif '/left' in request:
            control_motor('1', 'forward', 32768)
            control_motor('2', 'backward', 32768)
        elif '/right' in request:
            control_motor('1', 'backward', 32768)
            control_motor('2', 'forward', 32768)
        elif '/stop' in request:
            control_motor('1', 'stop', 0)
            control_motor('2', 'stop', 0)
        elif '/esc' in request:
            if 'mode=brake' in request:
                control_esc('brake')
            elif 'mode=half' in request:
                control_esc('half')
            elif 'mode=full' in request:
                control_esc('full')

        response = web_page()
        conn.send('HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n')
        conn.send(response)
        conn.close()
arm_esc()
# Activate AP mode with your SSID and Password
ap_mode('PicoW_Gamepad_Control', '123456789')
