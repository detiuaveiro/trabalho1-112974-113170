import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

# # Assuming you have data in the following format (replace with your actual data)
# widths = [10, 15, 20, 25, 30]
# heights = [20, 30, 40, 50, 60]
# times = [0.002, 0.003, 0.004, 0.005, 0.006]

# # Calculate the areas (width * height)
# areas = [w * h for w, h in zip(widths, heights)]

# Plotting the data
# plt.plot(areas, times, marker="o", linestyle="-", color="b")
# plt.title("Image Area vs. Time")
# plt.xlabel("Image Area")
# plt.ylabel("Time (seconds)")
# plt.grid(True)
# plt.show()

# read files and filter it
# remove #FOUND* from files

# Path: nossosTestes/tests.py
# Path: nossosTestes/tables/LocateTable.txt


# # fileLocate = pd.read_csv("./tables/LocateTable.txt", sep=",", header=None)
# print(fileLocate)
lines = []
counter = 0
filename = "./tables/LocateTable.txt"
mapStr = {"\t": "", " ": ""}
with open(filename, "r") as file:
    # lines.append(file.readline())
    header = file.readline()
    # remove '#' from firstline
    header = header.replace("#", "")
    header = header.replace("\n", "")
    header = " ".join(header.replace("\t", "").split())
    lines.append(header)
    # print(lines[0])
    for line in file:
        if not (line.startswith("#")):
            line = line.replace("\t", "")
            line = " ".join(line.split())
            lines.append(line)
            counter += 1
        # else:
        #     print("not found")


header = lines[0]
data = lines[1:]
# lets parse each line
for i in range(len(data)):
    data[i] = data[i].split(" ")
# print(headeve

df = pd.DataFrame(data, columns=header.split(" "))

df["width"] = df["width"].astype(int)
df["width2"] = df["width2"].astype(int)
df["time"] = df["time"].astype(float)
df["height"] = df["height"].astype(int)
df["height2"] = df["height2"].astype(int)
df["comparisons"] = df["comparisons"].astype(int)
df["numPixelsOrig"] = df["height"] * df["width"]
df["numPixelsSub"] = df["height2"] * df["width2"]


# Sorting by column 'Country'
# df.sort_values(by=['Country'])

time = np.sort(np.array(df["time"]))
df.sort_values(by=["comparisons"], inplace=True)
comps = np.array(df["comparisons"])
print(comps)
# areaSub = np.sort(np.array(df["numPixelsSub"]))
justw2 = np.array(df["width2"])
timeFit = np.polyfit(justw2, time, 2)
ncompsfit = np.polyfit(justw2, comps, 2)
polyComps = np.poly1d(ncompsfit)
poly = np.poly1d(timeFit)
a = ncompsfit[0]
b = ncompsfit[1]
c = ncompsfit[2]
print(f"{a}x^2 + {b}x + {c}")

y = a * np.square(justw2) + b * justw2 + c
t = np.linspace(-(10**4), 10**4, justw2.size)
y_fit = poly(t)
comps_fit = polyComps(t)
plt.plot(justw2, time, marker="o", color="b")
plt.plot(
    t,
    y_fit,
    label="y = " + str(a) + "x^2 + " + str(b) + "x + " + str(c),
    linestyle="-",
    color="r",
)
plt.show()
# another plot
plt.plot(justw2, comps, marker="o", color="b")
plt.plot(
    t,
    comps_fit,
    label="y = "
    + str(ncompsfit[0])
    + "x^2 + "
    + str(ncompsfit[1])
    + "x + "
    + str(ncompsfit[2]),
    linestyle="-",
    color="r",
    picker=True,
)
plt.show()
