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

    microplanetChance = random.randint(1,50)
    cloudChance = random.randint(1,10)
    ringChance = random.randint(1,10)
    moonChance = random.randint(1,10)
    ufoChance = random.randint(1,1000)
    starFissureChance = random.randint(1,1000)

    objects = []

    if microplanetChance > 49:
        print("generating microplanet")
        rTreeType = random.randint(0,1)
        print("tree type: " + str(rTreeType))
        objects = objects + [makeTrees(0) for x in range(random.randint(50,150))]
        objects = objects + [makeTrees(1) for x in range(random.randint(50,150))]
        if starFissureChance == 999:
            planet = Difference(
                drawPlanet([0.062, 0.2, 0.039], 'marble', .5, .5, [1,1,1], [0,0,0], [0,0,0]),
                drawStarFissure()
            )
        else:
            planet = drawPlanet([0.062, 0.2, 0.039], 'marble', .5, .5, [1,1,1], [0,0,0], [0,0,0])

        if (random.randint(1,10)) > 6:
            fire_tower = drawFireTower()
            objects = objects + [fire_tower]
        if (random.randint(1,10)) > 6:
            if(random.randint(1,2)) > 1:
                rocket = drawRocket()
            else:
                rocket = drawRocketOrbit()
            objects = objects + [rocket]


        objects = objects + [planet]

    else:
        objects = objects + [drawPlanet(planet_color, planet_normal, normal_mag, rMag(), [1,1,1], [0,0,0], [0,0,0])]
        
        #Generate chance of clouds

        if cloudChance > 100:
            print("clouds")
            objects = objects + [drawClouds()]
        elif ringChance > 6:
            print("rings")
            objects = objects + drawRings(planet_color)
        elif moonChance > 6:
            print("moons")
            objects = objects + drawMoon()
        
    if ufoChance == 999:
        objects = objects + [drawUFO()]

    #default camera ('angle', 30, 'location', [0.0,0,-10])

    scene = Scene( Camera('angle', 30,'location',  [0.0 , 0,-10],
                        'look_at', [0 , 0 , 0.0]),
                objects = objects + [sky, sun],
                included = ["colors.inc", "textures.inc"],
                defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

    scene.render("planet.png", includedirs=["./libraries"], width=800, height=600, antialiasing=0.001)

'''
def tweet_planet(api):
    imagePath = "./planet.png"
    render_planet()
    api.update_with_media(filename=imagePath, status=exoplanet_id())
    time.sleep(1800)

if __name__ == "__main__":
    tweet_planet(tweepy_creds())
'''

render_planet()