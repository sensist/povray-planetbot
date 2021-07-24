from vapory import *
import random
from os import environ
import time, string

import tweepy

def tweepy_creds():
    CONSUMER_KEY = environ['CONSUMER_KEY']
    CONSUMER_SECRET = environ['CONSUMER_SECRET']
    ACCESS_KEY = environ['ACCESS_KEY']
    ACCESS_SECRET = environ['ACCESS_SECRET']

    # Authenticate to Twitter
    auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
    auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)

    # Create API object
    return tweepy.API(auth)

def exoplanet_id():
    ID1 = random.choice(string.ascii_letters).upper()
    ID2 = random.choice(string.ascii_letters).upper()
    ID3 = random.randint(1000,9999)
    return(str(ID1+ID2) + "-" + str(ID3))

def rgb2pov(red,green,blue):
    red = red/255
    green = green/255
    blue = green/255
    return([red,green,blue])


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

def rMag():
    mag = random.random()+.1
    print(mag)
    return(mag)

def rScale():
    mag = random.randrange(1,5)/100
    print(mag)
    return(mag)

def rLight():
    x = random.randint(-50,50)
    y = random.randint(-50,50)
    z = random.randint(-50,0)
    return([x,y,z])

def makeTrees(rTreeType):
    if rTreeType == 0:
        trees = Union(
            Cylinder([0,0,0],[0,1,0], 0.15,
                Texture(Pigment ('color', rgb2pov(54, 36, 22)),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,0,0] 
            ),
            Cone([0,0,0],0.5,[0,1.5,0],0,
                Texture(Pigment('color', rgb2pov(14, 71, 29)),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,.5,0]
            ),
            'scale', [.1,.1,.1],
            'translate', [0,1,0],
            'rotate', [random.randint(-360,360),0,random.randint(-360,360)]
        )
    else:
        trees = Union(
            Cylinder([0,0,0],[0,1,0], 0.15,
                Texture(Pigment ('color', rgb2pov(54, 36, 22)),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,0,0] 
            ),
            Sphere ( [0,0,0], 1,
                Texture(Pigment('color', rgb2pov(14, 71, 29)),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,1.5,0],
                'scale', .5 
            ),
            'scale', [.1,.1,.1],
            'translate', [0,1,0],
            'rotate', [random.randint(0,360),0,random.randint(0,360)]
        )        
    return(trees)

def render_planet():

    planet_normal = choose_random_normal()
    normal_mag = rMag()
    if planet_normal == 'bozo' or planet_normal == "dents":
        print("bozo time")
        normal_mag = random.randint(1,15)
        print(normal_mag)
    
    sky = SkySphere (
        Pigment (
            'bozo',
            PigmentMap (
                [0.0, 'rgb',[.5,.5,.5]],
                [0.2, 'rgb',[0,0,0]],
                [1.0, 'rgb',[0,0,0]]
            ),
            'scale', .006,
            'rotate',[0,0,random.randint(0,360)]
        )
    )

    sun = LightSource([0, 0, 0],
            'color',[1, 1, 1],
            'area_light', [0,0,0],[10,0,-10], 4, 4,
            'adaptive', 0,
            'jitter',
            'translate', rLight())

    microplanetChance = random.randint(0,10)

    if microplanetChance > 11:
        print("generating microplanet")
        planet = Sphere ( [0,0,0], 1,
                Texture ( Pigment( 'color', generate_microplanet_color()),
                            Normal ( planet_normal, normal_mag, 'scale', rScale(), 'turbulence', rMag())                                    
                        ),
                'scale',[1,1,1],  
                'rotate',[0,0,0],  
                'translate',[0,0,0]  
            )
        rTreeType = random.randrange(0,1)
        trees = [makeTrees(rTreeType) for x in range(130)]
        clouds = []
    else:
        trees = []
        planet = Sphere ( [0,0,0], 1,
                Texture ( Pigment( 'color', generate_planet_color()),
                            Normal ( planet_normal, normal_mag, 'scale', rScale(), 'turbulence', rMag())                                    
                        ),
                'scale',[1,1,1],  
                'rotate',[0,0,0],  
                'translate',[0,0,0]  
            )
        cloudChance = random.randint(1,10)
        if cloudChance > 6:
            clouds = [Sphere ( [0,0,0], 1,
                    Texture ( 
                    Pigment( 'bozo', 
                        'scale', 0.1, 
                        'turbulence', 0,
                        ColorMap([0.00, 'rgb', [0.95, 0.95, 0.95]],
                                [0.10, 'rgb', [1, 1, 1]],
                                [0.15, 'rgb', [0.85,0.85,0.85,.25]],
                                [0.50, 'rgb', [1,1,1,1]],
                                [1.00, 'rgb', [1,1,1,1]]
                            )
                        )
                    ),
                    'scale',1.02,  
                    'rotate',[random.randint(0,360),random.randint(0,360),random.randint(0,360)],  
                    'translate',[0,0,0]  
                )]
        else:
            clouds = []


    scene = Scene( Camera('angle', 75,'location',  [0.0 , 0,-2.5],
                        'look_at', [0 , 0 , 0.0]),
                objects = [sky, sun, planet] + trees + clouds,
                included = ["colors.inc", "textures.inc"],
                defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

    scene.render("planet.png", includedirs=["./libraries"], width=800, height=600, antialiasing=0.001)

def tweet_planet(api):
    imagePath = "./planet.png"
    render_planet()
    api.update_with_media(filename=imagePath, status=exoplanet_id())
    time.sleep(7200)

if __name__ == "__main__":
    tweet_planet(tweepy_creds())