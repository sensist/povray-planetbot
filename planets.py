from vapory import *
import random
from os import environ

import tweepy

'''
CONSUMER_KEY = environ['CONSUMER_KEY']
CONSUMER_SECRET = environ['CONSUMER_SECRET']
ACCESS_KEY = environ['ACCESS_KEY']
ACCESS_SECRET = environ['ACCESS_SECRET']

print(CONSUMER_KEY)
print(CONSUMER_SECRET)
print(ACCESS_KEY)
print(ACCESS_SECRET)

# Authenticate to Twitter
auth = tweepy.OAuthHandler(CONSUMER_KEY, CONSUMER_SECRET)
auth.set_access_token(ACCESS_KEY, ACCESS_SECRET)

# Create API object
api = tweepy.API(auth)

# Create a tweet
#api.update_status("Hello World!")
'''

def generate_planet_color():
    R = random.random()
    G = random.random()
    B = random.random()
    return([R,G,B])

def choose_random_normal():
    choices = [
        'agate',
        'bozo',
        'mandel',
        'bumps',
        'crackle',
        'granite',
        'dents']
    choice = random.randint(0,len(choices)-1)
    print(choice)
    return(choices[choice])

def rMag():
    mag = random.random()
    return(mag)

sky = SkySphere (
	Pigment (
		'bozo',
		PigmentMap (
			[0.0, 'rgb',[.5,.5,.5]],
			[0.2, 'rgb',[0,0,0]],
			[1.0, 'rgb',[0,0,0]]
        ),
		'scale', .006
    )
)

sun = LightSource([50, 20, -15],
        'color',[1, 1, 1],
        'translate', [-5, 5, -5])

planet = Sphere ( [0,0,0], 1,
         Texture ( Pigment( 'color', generate_planet_color()),
                    Normal ( choose_random_normal(), rMag(), 'scale', rMag(), 'turbulence', rMag())                                    
                 ),
          'scale',[.75,.75,.75],  
          'rotate',[0,0,0],  
          'translate',[0,0,0]  
       )

scene = Scene( Camera('angle', 75,'location',  [0.0 , 0,-2.0],
                      'look_at', [0 , 0 , 0.0]),
               objects = [sky, sun, planet],
               included = ["colors.inc", "textures.inc"],
               defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

scene.render("planet.png", includedirs=["./libraries"], width=400, height=300, antialiasing=0.001)