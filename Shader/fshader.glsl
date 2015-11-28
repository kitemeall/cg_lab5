
varying vec3 position;
varying vec3 normal;

void main(void)
{
    vec3 ambient = vec3(0.02, 0.02, 0.02);
    vec3 surf2light = normalize(- position);
    vec3 norm = normalize(normal);
    float dcont = abs(dot(norm, surf2light));
    vec3 diffuse = dcont * vec3(0.5, 0.5, 0.5);

    vec3 reflection = reflect(-surf2light, norm );

    float scont = pow(max(0.0, dot(surf2light, reflection)), 20);
    vec3 specular = scont * vec3(1.0, 1.0, 1.0);

    gl_FragColor = vec4( ambient + diffuse + specular, 1.0 );

}
