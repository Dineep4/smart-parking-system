import serial
import json

#d:\CBP_PROJECTS\DT_CBP\Smart_Parking_System\reader.py

ser = serial.Serial('COM5', 9600)  # change if needed

while True:
    try:
        line = ser.readline().decode().strip()

        if line.startswith("{") and line.endswith("}"):
            data = json.loads(line)

            with open("./data.json", "w") as f:
                json.dump(data, f, indent=2)

            print("Updated:", data)

    except Exception as e:
        print("Error:", e)
        