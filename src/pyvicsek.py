import numpy as np
import matplotlib.pyplot as plt
import glob
import natsort
from matplotlib.animation import FuncAnimation

def read_config(filename, skip=2):
    """Reading an vicsek configuration from a file handle"""
    with open(filename) as file_handle:
        # skip the first two lines
        for i in range(skip): 
            next(file_handle)

        data = np.loadtxt(file_handle)
        conf = {}

        conf["id"] = data[:,0]
        conf["x"] = data[:,1]
        conf["y"] = data[:,2]
        conf["theta"] = data[:,3]
        conf["vx"] = np.cos(conf["theta"])
        conf["vy"] = np.sin(conf["theta"])  
        return conf
    
def plot(conf,ax):
    qv = ax.quiver(conf["x"], conf["y"], conf["vx"], conf["vy"], conf["theta"], scale=1, scale_units='xy', cmap='hsv')

    return qv


# files are stored in a folder
files = natsort.natsorted(glob.glob("frames/*"))

# first plot
fig, ax= plt.subplots(figsize=(5,5), frameon=False) 

qv = plot(read_config(files[0]),ax)

ax.axis('equal')
ax.axis('off')


# function called to plot all files
def animate(i):
    #print(i)
    conf = read_config(files[i])
    pos = np.array(list(zip(conf["x"], conf["y"])))
    #print(pos)
    qv.set_offsets(pos)
    qv.set_UVC(conf["vx"], conf["vy"], conf["theta"])
    
# Create the animation
anim = FuncAnimation(fig,animate, range(len(files)), interval=30)
# Show the animation
plt.show()