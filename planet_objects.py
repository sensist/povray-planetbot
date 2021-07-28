from vapory import *
from utils import *
from gen import *

import random

def makeTrees(rTreeType):
    if rTreeType == 0:
        trees = Union(
            Cylinder([0,0,0],[0,1,0], 0.15,
                Texture(Pigment ('color', rgb2pov(54, 36, 22)),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,0,0] 
            ),
            Cone([0,0,0],0.5,[0,1.5,0],0,
                Texture(Pigment('color', [0.066, 0.152, 0.066]),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,.5,0]
            ),
            Cone([0,0,0],0.5,[0,1.5,0],0,
                Texture(Pigment('color', [0.066, 0.152, 0.066]),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,.75,0]
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
                Texture(Pigment('color', [0.066, 0.152, 0.066]),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                'translate', [0,1.5,0],
                'scale', .5 
            ),
            'scale', [.1,.1,.1],
            'translate', [0,1,0],
            'rotate', [random.randint(0,360),0,random.randint(0,360)]
        )        
    return(trees)

def drawStars():
    stars = SkySphere (
            Pigment (
                'bozo',
                PigmentMap (
                    [0.0, 'rgb',[.5,.5,.5]],
                    [0.2, 'rgb',[0,0,0]],
                    [1.0, 'rgb',[0,0,0]]
                ),
                'scale', .003,
                'rotate',[0,0,random.randint(0,360)]
            )
        )
    return(stars)

def drawSun():
    sun = LightSource([0, 0, 0],
                'color',[1, 1, 1],
                'area_light', [0,0,0],[10,0,-10], 4, 4,
                'adaptive', 0,
                'jitter',
                'translate', rLight())
    return(sun)

def drawPlanet(color, normal, normal_mag,mag, scale, rotate, translate):
    planet = Sphere ( [0,0,0], 1,
        Texture ( 
            Pigment( 'color', color),
            Normal ( normal, normal_mag, 'scale', mag, 'turbulence', mag)                                    
        ),
        'scale',scale,  
        'rotate',rotate,  
        'translate',translate  
        )
    return(planet)

def drawClouds():

    scale = random.random()

    clouds = Sphere ( [0,0,0], 1,
                        Texture ( 
                        Pigment( 'bozo',
                            'scale',.15,
                            ColorMap([0.00, 'rgb', [0.95, 0.95, 0.95]],
                                    [0.10, 'rgb', [1, 1, 1]],
                                    [0.15, 'rgb', [0.85,0.85,0.85,.25]],
                                    [0.50, 'rgb', [1,1,1,1]],
                                    [1.00, 'rgb', [1,1,1,.85]]
                                )
                            ),
                            'translate',[0,3,0]
                        ),
                        'scale',1.02,  
                        'rotate',[random.randint(0,360),random.randint(0,360),random.randint(0,360)],  
                        'translate',[0,0,0]  
                    )
    return(clouds)

def drawRings(planet_color):

    invert_chance = random.randint(0,9)

    ring_rot_x = 90 + random.randint(-15,15)
    ring_rot_y = random.randint(-45,45)
    ring_rot_z = random.randint(-45,45)

    if invert_chance > 6:
        ring_color = [planet_color[0]+random.random(),planet_color[1]+random.random(),planet_color[2]+random.random()]
    else:
        ring_color = [1-planet_color[0]+random.random(),1-planet_color[1]+random.random(),1-planet_color[2]+random.random()]

    rings = [
        Difference(
        Cylinder([0,0,0],[0,0,.005], 2,
                Texture(Pigment ('wood', 'frequency',3,
                    ColorMap([0.00,'rgb', [ring_color[0],ring_color[1],ring_color[2], 0]],
                             [0.10,'rgb', [ring_color[0],ring_color[1],ring_color[2], .85]],
                             [0.45,'rgb', [1,1,1,1]],
                             [0.7, 'rgb', [ring_color[0],ring_color[1],ring_color[2], .5]],
                             [1.00,'rgb', [ring_color[0],ring_color[1],ring_color[2], .95]]
                    )
                )
            ),
                Finish('ambient',.8),
                'translate', [0,0,0],
                'rotate',[ring_rot_x, ring_rot_y, ring_rot_z] 
            ),
        Cylinder([0,0,-1],[0,0,1], 1.05,
                Texture(Pigment ('color', [1,1,1,.5]),
                Normal('marble',.5,'scale',.5,'turbulence',.5)),
                Finish('ambient',.8),
                'translate', [0,0,0],
                'rotate',[ring_rot_x, ring_rot_y, ring_rot_z] 
            ),
        'scale',[1.15,1.15,1.15]
        )
    ]
    return(rings)

def drawMoon():

    moon_normal = choose_random_normal()

    moon_rot_x = random.randint(-15,15)
    moon_rot_y = random.randint(-45,45)
    moon_rot_z = random.randint(-45,45)

    moon = [Sphere ( [0,0,0], 1,
        Texture ( 
            Pigment( 'color', [1,.9,.8]),
            Normal ( moon_normal, .5, 'scale', .5)                                    
        ),
        'scale',.15,
        'translate',[1.75,0,0],
        'rotate',[moon_rot_x,0,moon_rot_z] 
        )]
    return(moon)

def drawUFO():

    ufo_pos_x = random.randint(0,2)
    if ufo_pos_x == 0:
        ufo_pos_x = -2
    ufo_pos_y = random.randrange(-1,1)

    ufo = Union(
        Sphere([0,0,0],1,
            Texture (
            Pigment ('color', [0,1,0]),
            Finish ('reflection', .25)
            ),
        'scale',.25,
        'translate',[0,.2,0]
        ),
        Cone([0,0,0],1,[0,.25,0],0,
            Texture(Pigment('color', [.75,.75,.75]),
            Finish('metallic',.75))
        ),
        Cone([0,0,0],1,[0,.25,0],0,
            Texture(Pigment('color', [.75,.75,.75]),
            Finish('metallic',.75, 'reflection', .25)),
            'rotate',[180,0,0]
        ),
        'scale',.25,
        'translate',[ufo_pos_x,ufo_pos_y,0]
    )
    return(ufo)

def drawFireTower():
    fire_tower = Union(
        Difference(
            Difference(
                Difference( #tower+legs
                    Box([0,0,0],[2,6.25,2],
                        Pigment('color', 'White')
                    ),
                    Union(
                        Box([.25,0,-5],[1.75,4.5,5],
                        Pigment('color', 'White'),
                        'translate', [0,0,1]
                        ),
                        Box([-5,0,.25],[5,4.5,1.75],
                        Pigment('color', 'White'),
                        'translate',[1,0,0]
                        )
                    )
                ),
                Box([.1,4.75,.1],[1.9,6,1.9],
                    Texture(Pigment('color', [.38,.38,.38]))
                )
            ),
            Union(
                Box([1.1,5.15,-5],[1.9,5.85,5]),
                Box([.1,5.15,-5], [.95,5.85,5]),
                Box([-5,5.15,.1], [5,5.85,.95]),
                Box([-5,5.15,1.1],[5,5.85,1.9]),
                Texture(Pigment('color', [.38,.38,.38]))
            )
        ),
        Difference(
            Union(
                Box([0,0,0],[.25,2.5,2],
                    Pigment('color','White'),
                    'rotate',[0,0,-45],
                    'translate',[0,.25,0]
                ),
                Box([0,0,0],[.25,2.5,2],
                    Pigment('color','White'),
                    'rotate',[0,0,45],
                    'translate',[1.75,2,0]
                )
            ),
            Box([-3,0,.25],[3,6.25,1.75],
                Pigment('color', 'White')
            ),
            'rotate',[0,90,0],
            'translate',[0,.25,2]
        ),

        Difference(
            Union(
                Box([0,0,0],[.25,2.5,2],
                    Pigment('color','White'),
                    'rotate',[0,0,-45],
                    'translate',[0,.25,0]
                ),
                Box([0,0,0],[.25,2.5,2],
                    Pigment('color','White'),
                    'rotate',[0,0,45],
                    'translate',[1.75,2,0]
                )
            ),
            Box([-3,0,.25],[3,6.25,1.75],
                Pigment('color', 'White')
            ),
            'translate',[0,.25,0]
        ),
        Prism('conic_sweep',0,1,5,
            [1,1],
            [-1,1],
            [-1,-1],
            [1,-1],
            [1,1],
            Texture(Pigment('color', [.38,.38,.38])),
            'rotate',[180,0,0],
            'scale',[1.25,1,1.25],
            'translate',[1,7.15,1]
        ),
        'scale', [.05,.05,.05],
        'translate', [0,1,0],
        'rotate', [random.randint(-120,-10),0,random.randint(-120,-10)]
    )
    return(fire_tower)

def drawTent():
    tent = Union(
        Difference(
            Prism(0,2,4,
                [-1,0],
                [1,0],
                [0,2],
                [-1,0],
                Texture(Pigment('color', [0.470, 0.415, 0.247])),
                'rotate',[-90,0,0],
                'translate',[0,0,0],
            ),
            Prism(0,1.75,4,
                    [-1,0],
                    [1,0],
                    [0,2],
                    [-1,0],
                    Texture(Pigment('color', [0.470, 0.415, 0.247])),
                    'scale',[.95,3,.85],
                    'rotate',[-90,0,0],
                    'translate',[0,0,0],
                ) 
        ), 
        Union(
            Merge(
                Cylinder([0,0,0],[0,0,2], 0.2,
                    Texture(Pigment ('color', [0.227, 0.164, 0.094]),
                    Normal('wood',1,'scale',.5,'turbulence',.5)),
                    'translate', [0,0,0] 
                ),
                Cylinder([0,0,0],[0,0,2], 0.185,
                    Texture(Pigment ('color', [0.627, 0.494, 0.329]),
                    Normal('wood',1,'scale',.5,'turbulence',.5)),
                    'translate', [0,0,0] 
                ),
                'translate',[0,0,-1]
            ),
            Merge(
                Cylinder([0,0,0],[0,0,2], 0.2,
                    Texture(Pigment ('color', [0.227, 0.164, 0.094]),
                    Normal('wood',1,'scale',.5,'turbulence',.5)),
                    'translate', [0,0,0] 
                ),
                Cylinder([0,0,0],[0,0,2], 0.185,
                    Texture(Pigment ('color', [0.627, 0.494, 0.329]),
                    Normal('wood',1,'scale',.5,'turbulence',.5)),
                    'translate', [0,0,0] 
                ),
                'rotate',[0,90,0],
                'translate',[-1,0,0]
            ),
            'rotate',[.75,.75,.75],
            'rotate',[0,45,0],
            'translate',[0,0,-3.5]           
        ),
        'scale', [.05,.05,.05],
        'translate', [0,.99,0],
        'rotate', [random.randint(-120,-30),0,random.randint(-120,-30)]
    )
    return(tent)     