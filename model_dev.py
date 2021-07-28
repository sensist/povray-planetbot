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
        )
    )

scene = Scene( Camera('angle', 30,'location',  [20.0 , 20,-20],
                        'look_at', [0 , 0 , 0.0]),
                objects = [sky, sun, ground,model],
                included = ["colors.inc", "textures.inc"],
                defaults = [Finish( 'ambient', 0.1, 'diffuse', 0.9)] )

scene.render("model_dev.png", includedirs=["./libraries"], width=800, height=600, antialiasing=0.001)
