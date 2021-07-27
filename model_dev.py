from vapory import *

sun = LightSource([-2500,2500,-1500], 'color', 'White')


sky = Plane([0,1,0], 1, 'hollow',  
            Texture( Pigment( 'bozo',
                              'turbulence', 0.92,
                               PigmentMap( [0.00, 'rgb', [0.18, 0.18, .9]],
                                           [0.50, 'rgb', [0.18, 0.18, .9]],
                                           [0.70, 'rgb', [1,1,1]],
                                           [0.85, 'rgb', [0.25,0.25,0.25]],
                                           [1.0 , 'rgb', [0.5,0.5,0.5]]),
                              'scale', [2.5,2.5,3.75],
                              'translate', [-1.25,0,0]),
            Finish('ambient', 1, 'diffuse', 0)),
            'scale', 10000)

ground = Plane( [0,1,0], 0, 
            Texture( Pigment( 'color', 'rgb', [1,.5,.5]),
                     Normal('bumps', 0.75, 'scale', 0.0125),
                     Finish('phong', 0.1))) 

model = Union(
    Difference(
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
    'translate', [0,0,-2]
)
scene = Scene( Camera('angle', 30,'location',  [20.0 , 20,-20],
                        'look_at', [0 , 0 , 0.0]),
                objects = [sky, sun, ground,model],
                included = ["colors.inc", "textures.inc"],
                defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

scene.render("model_dev.png", includedirs=["./libraries"], width=800, height=600, antialiasing=0.001)
