uniform float Opacity;

varying vec3 position;
varying vec3 normal;

uniform vec3 lightPos;

uniform vec3 mambient;
uniform vec3 mdiffuse;
uniform vec3 mspecular;
uniform float shininess;

uniform vec3 lambient;
uniform vec3 ldiffuse;
uniform vec3 lspecular;


void main(void)
{
    vec3 ambient = mambient * lambient;
    vec3 surf2light = normalize(lightPos - position);
    vec3 norm = normalize(normal);
    float dcont = max(0.0, dot(norm, surf2light));
    vec3 diffuse = dcont * mdiffuse * ldiffuse;

    vec3 surf2view = normalize(- position);
    vec3 reflection = reflect(-surf2light, norm );

    float scont = pow(max(0.0, dot(surf2view, reflection)), shininess);
    vec3 specular = scont * lspecular * mspecular;

    gl_FragColor = vec4( ambient + diffuse + specular, 1.0 );


}
