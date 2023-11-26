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
filename = "./tables/LocateTable4.txt"
mapStr = {"\t": "", " ": ""}
with open(filename, "r") as file:
    # lines.append(file.readline())
    header = file.readline()
    # remove '#' from firstline
    header = header.replace("#", "")
    header = header.replace("\n", "")
    header = " ".join(header.replace("\t", "").split())
    header += " X Y"
    lines.append(header)
    for line in file:
        if not (line.startswith("#")):
            line = line.replace("\t", "")
            line = " ".join(line.split())
            lines.append(line)
            counter += 1
        else:
            if line.startswith("# FOUND"):
                lines[-1] = (
                    lines[-1]
                    + " "
                    + line.replace("# FOUND ", "")
                    .replace("(", "")
                    .replace(")", "")
                    .replace(",", " ")
                    .replace("\n", "")
                )


# print(lines)

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
df["X"] = df["X"].astype(int)
df["Y"] = df["Y"].astype(int)
df["numPixelsOrig"] = df["height"] * df["width"]
df["numPixelsSub"] = df["height2"] * df["width2"]
df["index"] = df["X"] * df["width"] + df["Y"]

# Sorting by column 'Country'
# df.sort_values(by=['Country'])

# time = np.sort(np.array(df["time"]))
# df.sort_values(by=["comparisons"], inplace=True)
# comps = np.array(df["comparisons"])
# print(comps)
# # areaSub = np.sort(np.array(df["numPixelsSub"]))
# justw2 = np.array(df["width2"])
# timeFit = np.polyfit(justw2, time, 2)
# ncompsfit = np.polyfit(justw2, comps, 2)
# polyComps = np.poly1d(ncompsfit)
# poly = np.poly1d(timeFit)
# a = ncompsfit[0]
# b = ncompsfit[1]
# c = ncompsfit[2]
# print(f"{a}x^2 + {b}x + {c}")

# y = a * np.square(justw2) + b * justw2 + c
# t = np.linspace(-(10**0), 10**4, justw2.size)
# y_fit = poly(t)
# comps_fit = polyComps(t)
# plt.scatter(justw2, time, marker="o", color="b")
# plt.plot(
#     t,
#     y_fit,
#     label="y = " + str(a) + "x^2 + " + str(b) + "x + " + str(c),
#     linestyle="-",
#     color="r",
# )
# plt.show()
# # another plot
# plt.scatter(justw2, comps, marker="o", color="b")
# plt.plot(
#     t,
#     comps_fit,
#     label="y = "
#     + str(ncompsfit[0])
#     + "x^2 + "
#     + str(ncompsfit[1])
#     + "x + "
#     + str(ncompsfit[2]),
#     linestyle="-",
#     color="r",
#     picker=True,
# )
# plt.show()

df = df.sort_values(by=["index"])
# print(df)
print(len(df["numPixelsOrig"]))

df.to_csv("./tables/LocateTable.csv")
# print(df["comparisons"])

plt.scatter(
    np.array(df["numPixelsSub"]), np.array(df["comparisons"]), marker="o", color="b"
)
plt.xlabel("numPixelsSub")
plt.ylabel("comps")

plt.show()
# NAO SEI O QUE FAZER

# plt.scatter(np.array(df["width2"]), np.array(df["comparisons"]), marker="o", color="b")
# plt.xlabel("width2")
# plt.ylabel("comps")

# plt.show()

## to blurPerfect tables

blurPerfectLines = []
blurPerfectFile = "./tables/BlurTableStor.txt"
mapStrBlurPerfect = {"\t": "", " ": ""}

with open(blurPerfectFile, "r") as file:
    # lines.append(file.readline())
    header = file.readline()
    # remove '#' from firstline
    header = header.replace("#", "")
    header = header.replace("\n", "")
    header = " ".join(header.replace("\t", "").split())
    blurPerfectLines.append(header)
    # print(blurPerfectLines[0])
    for line in file:
        if not (line.startswith("#")):
            line = line.replace("\t", "")
            line = " ".join(line.split())
            blurPerfectLines.append(line)
        # else:
        #     print("not found")
blurPerfectHeader = blurPerfectLines[0]
blurPerfectData = blurPerfectLines[1:]
for i in range(len(blurPerfectData)):
    blurPerfectData[i] = blurPerfectData[i].split(" ")
dfBlurPerfect = pd.DataFrame(blurPerfectData, columns=blurPerfectHeader.split(" "))


dfBlurPerfect["width"] = dfBlurPerfect["width"].astype(int)
dfBlurPerfect["width2"] = dfBlurPerfect["width2"].astype(int)
dfBlurPerfect["time"] = dfBlurPerfect["time"].astype(float)
dfBlurPerfect["height"] = dfBlurPerfect["height"].astype(int)
dfBlurPerfect["addsOrSubs"] = dfBlurPerfect["addsOrSubs"].astype(int)

dfBlurPerfect["height2"] = dfBlurPerfect["height2"].astype(int)
dfBlurPerfect["comparisons"] = dfBlurPerfect["comparisons"].astype(int)
dfBlurPerfect["numPixelsOrig"] = dfBlurPerfect["height"] * dfBlurPerfect["width"]
dfBlurPerfect["numPixelsSub"] = dfBlurPerfect["height2"] * dfBlurPerfect["width2"]
dfBlurPerfect["dx"] = dfBlurPerfect["dx"].astype(int)
dfBlurPerfect["dy"] = dfBlurPerfect["dy"].astype(int)
dfBlurPerfect = dfBlurPerfect.sort_values(by=["width"], ascending=True)
# print(dfBlurPerfect)
dfBlurPerfect.to_csv("./tables/BlurTableStorPerfect.csv")

plt.scatter(
    dfBlurPerfect["numPixelsOrig"], dfBlurPerfect["addsOrSubs"], marker="o", color="b"
)
plt.title("Blur Perfect")
plt.show()


## to blurBad tables

blurBadLines = []
blurBadFile = "./tables/BlurTableBadStor.txt"
mapStrBlurBad = {"\t": "", " ": ""}

with open(blurBadFile, "r") as file:
    # lines.append(file.readline())
    header = file.readline()
    # remove '#' from firstline
    header = header.replace("#", "")
    header = header.replace("\n", "")
    header = " ".join(header.replace("\t", "").split())
    blurBadLines.append(header)
    # print(blurBadLines[0])
    for line in file:
        if not (line.startswith("#")):
            line = line.replace("\t", "")
            line = " ".join(line.split())
            blurBadLines.append(line)
        # else:
        #     print("not found")
blurBadHeader = blurBadLines[0]
blurBadData = blurBadLines[1:]
for i in range(len(blurBadData)):
    blurBadData[i] = blurBadData[i].split(" ")
dfBlurBad = pd.DataFrame(blurBadData, columns=blurBadHeader.split(" "))


dfBlurBad["width"] = dfBlurBad["width"].astype(int)
dfBlurBad["width2"] = dfBlurBad["width2"].astype(int)
dfBlurBad["time"] = dfBlurBad["time"].astype(float)
dfBlurBad["height"] = dfBlurBad["height"].astype(int)
dfBlurBad["addsOrSubs"] = dfBlurBad["addsOrSubs"].astype(int)

dfBlurBad["height2"] = dfBlurBad["height2"].astype(int)
dfBlurBad["comparisons"] = dfBlurBad["comparisons"].astype(int)
dfBlurBad["numPixelsOrig"] = dfBlurBad["height"] * dfBlurBad["width"]
dfBlurBad["numPixelsSub"] = dfBlurBad["height2"] * dfBlurBad["width2"]
dfBlurBad["dx"] = dfBlurBad["dx"].astype(int)
dfBlurBad["dy"] = dfBlurBad["dy"].astype(int)
dfBlurBad = dfBlurBad.sort_values(by=["width"], ascending=True)
# print(dfBlurBad)
dfBlurBad.to_csv("./tables/BlurTableBADStor.csv")

plt.scatter(dfBlurBad["numPixelsOrig"], dfBlurBad["addsOrSubs"], marker="o", color="b")
plt.scatter(
    dfBlurPerfect["numPixelsOrig"], dfBlurPerfect["addsOrSubs"], marker="o", color="r"
)
plt.title("Blur Perfect")
plt.title("Blur Bad")
plt.show()


"""
Sum[Sum[Sum[Sum[2,{l,0,Subscript[h,2]-1}],{k,0,Subscript[w,2]-1}],{j,0,h-Subscript[h,2]-1}],{i,0,w-Subscript[w,2]-1}] = 2(h-Subscript[h,2])*Subscript[h,2](w-Subscript[w,2])* Subscript[w,2]

"""


# # %%


# n = 1
# lines = []
# with open("./tables/LocateTable.csv", "r") as file:
#     for line in file:
#         if not (n % 2 == 0):
#             lines.append(line)
#         n += 1


# with open("./tables/LocateTableSemLixo.csv", "w") as file:
#     for line in lines:
#         file.write(line)

# # %%
