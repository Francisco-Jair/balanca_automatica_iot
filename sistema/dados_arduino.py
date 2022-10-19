from datetime import datetime
import serial
from sms_whats import enviar

arduino = serial.Serial("/dev/cu.usbmodem101", 115200)

trava = True

while True:
    data_hora = datetime.now()
    # data_texto = datetime.strftime("%Y-%m-%d")
    linha = str(arduino.readline())
    a = linha.split(' ')[-1].split('\\r')[0]
    print(float(a))

    if float(a) < 2.85 and trava:
        trava = False
        enviar(data_hora)
        # print("OK")