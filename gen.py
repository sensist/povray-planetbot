import random, string
from vapory import *
from utils import *

def exoplanet_id():
    ID1 = random.choice(string.ascii_letters).upper()
    ID2 = random.choice(string.ascii_letters).upper()
    ID3 = random.randint(1000,9999)
    return(str(ID1+ID2) + "-" + str(ID3))

def generate_planet_color():
    R = random.random()
    G = random.random()
    B = random.random()
    return([R,G,B])

def generate_microplanet_color():
    R = random.randint(25,70)
    G = random.randint(40,70)
    B = 25
    rgb = rgb2pov(R,G,B)
    return(rgb)

def color_variation(color):
    R = color[0]+(random.randint(-5,5)/100)
    G = color[1]+(random.randint(-5,5)/100)
    B = color[2]+(random.randint(-5,5)/100)
    return([R,G,B])

def choose_random_normal():
    choices = [
        'agate',
        'bozo',
        'bumps',
        'crackle',
        'granite',
        'dents']
    choice = random.randint(0,len(choices)-1)
    print(choices[choice])
    return(choices[choice])

def choose_moon_normal():
    choices = [
        'bumps',
        'crackle',
        'dents',
        'granite']
    choice = random.randint(0,len(choices)-1)
    print(choices[choice])
    return(choices[choice])

def rMag():
    mag = random.random()+.1
    print(mag)
    return(mag)

def rScale():
    mag = random.randrange(1,8)/100
    print(mag)
    return(mag)

def rLight():
    x = random.randint(-50,50)
    y = random.randint(-50,50)
    z = random.randint(-50,0)
    return([x,y,z])