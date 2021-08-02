from vapory import *
import random

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
model = Union()

rocket = Union(
    Difference(
        Union(
            Sphere([0,0,0],1,
                Pigment('color','White'),
                'scale',[1,2.5,1],
                'translate',[0,2,0]
            ),
            Cone([0,0,0],.75, [0,2,0],0,
                Pigment('color','Red'),
                'translate',[0,3.65,0]
            )
        ),
        Box([-1,-1,-1],[1,.15,1])
    ),
    Difference(
        Difference(
            Union (
                Cylinder([0,0,0],[0,0,.1],2,
                    'translate',[0,-1,0]
                ),
                Cylinder([0,0,0],[.1,0,0],2,
                    'translate',[0,-1,0]
                ),
            ),
            Sphere([0,0,0],1.5,
                'translate',[0,-1.5,0]
            ),
            Pigment('color', 'Red'),
            'translate',[0,.5,0]
        ),
        Box([-4,-4,-4],[4,-2,4])
    ),
    'rotate',[0,45,0],
    'translate',[0,2,0]
)

lattice = Union(
            Box([0,0,0],[.1,1.25,.1],
                'rotate',[0,0,-45]
            ),
            Box([0,0,0],[.1,1.25,.1],
                'rotate',[0,0,45],
                'translate',[.9,1,0]
            ),
            Box([0,0,0],[.1,1.25,.1],
                'rotate',[0,0,-45],
                'translate',[0,2,0]
            ),
            Box([0,0,0],[.1,1.25,.1],
                'rotate',[0,0,45],
                'translate',[.9,3,0]
            ),
            Box([0,0,0],[.1,1.25,.1],
                'rotate',[0,0,-45],
                'translate',[0,4,0]
            ),
            Pigment('color','Grey'),
            'translate',[0,.5,0],
        )

model = Union(
    rocket,
    Union(
        Difference(
            Box([0,0,0],[1,5.5,1],
                Pigment('color','Grey')
            ),
            Union(
                Box([-2,0,.1],[2,5.4,.9],
                    'translate',[1,0,0]
                ),
                Box([.1,0,2],[.9,5.4,-2],
                    'translate',[0,0,0]
                ),
                Pigment('color', 'Grey')           
            )
        ),
        lattice,
        Union(
            lattice,
            'rotate',[0,90,0],
            'translate',[0,0,1]
        ),
        Union(
            lattice,
            'rotate',[0,-90,0],
            'translate',[1,0,0]
        ),
        Union(
            lattice,
            'translate',[0,0,1]
        ),
        'translate',[-2.5,0,-.5]
    ),

)


scene = Scene( Camera('angle', 30,'location',  [20.0 , 20,-20],
                        'look_at', [0 , 0 , 0.0]),
                objects = [sky, sun, ground,model],
                included = ["colors.inc", "textures.inc"],
                defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

scene.render("model_dev.png", includedirs=["./libraries"], width=800, height=600, antialiasing=0.001)
