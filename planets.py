import random, time, string
from os import environ
from vapory import *
from gen import *
from planet_objects import *
from utils import *

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

def render_planet():

    planet_normal = choose_random_normal()
    planet_color = generate_planet_color()
    normal_mag = rMag()
    if planet_normal == 'bozo' or planet_normal == "dents":
        normal_mag = random.randint(1,15)
        print(normal_mag)
    
    sky = drawStars()

    sun = drawSun()

    microplanetChance = random.randint(0,10)

    if microplanetChance > 6:
        print("generating microplanet")
        planet = drawPlanet(generate_microplanet_color(), planet_normal, normal_mag, rMag(), [1,1,1], [0,0,0], [0,0,0])
        rTreeType = random.randint(0,1)
        print("tree type: " + str(rTreeType))
        trees = [makeTrees(rTreeType) for x in range(130)]
        clouds = []
        rings = []
    else:
        trees = []
        planet = drawPlanet(planet_color, planet_normal, normal_mag, rMag(), [1,1,1], [0,0,0], [0,0,0])
        
        #Generate chance of clouds
        cloudChance = random.randint(1,10)
        ringChance = random.randint(1,10)
        if cloudChance > 6:
            clouds = [drawClouds()]
            rings = []
        else:
            clouds = []
            if ringChance > 6:
                rings = drawRings(planet_color)
            else:
                rings = []



    scene = Scene( Camera('angle', 75,'location',  [0.0 , 0,-3.5],
                        'look_at', [0 , 0 , 0.0]),
                objects = [sky, sun, planet] + trees + clouds + rings,
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