import numpy as np
import matplotlib.pyplot as plt
import serial

pan = []
tilt = []
r = []
done = False

ser = serial.Serial('COM6', 9600, timeout=1)
while not done:
    data_read = ser.readline().decode().strip()
    if data_read == "done":
        done == True
    else:
        data_read = data_read.split(",")
        pan.append(data_read[0])
        tilt.append(data_read[1])
        r.append(np.median(data_read[2:]))

THETA, PHI, R = np.meshgrid(pan, tilt, r)
X = R * np.sin(PHI) * np.cos(THETA)
Y = R * np.sin(PHI) * np.sin(THETA)
Z = R * np.cos(PHI)
fig = plt.figure()
ax = fig.add_subplot(1,1,1, projection='3d')
plot = ax.plot_surface(
    X, Y, Z, rstride=1, cstride=1, cmap=plt.get_cmap('jet'),
    linewidth=0, antialiased=False, alpha=0.5)

plt.show()