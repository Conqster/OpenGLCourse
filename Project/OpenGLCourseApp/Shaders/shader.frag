#version 330	
			
in vec4 vCol;
in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
					
out vec4 colour;
const int MAX_POINT_LIGHTS = 3;

struct Light
{ 
    vec3 colour;
	float ambientIntensity;
    float diffuseintensity;
}

struct DirectionalLight
{
	Light base;
    vec3 direction;
};

struct PointLight
{
    Light base;
    vec3 position;
    float constant;
    float linear;
    float exponent;
}

struct Material
{
	float specularIntensity;
	float shininess;
};

uniform int pointLightCount;
	
uniform DirectionalLight directionalLight;
uniform PointLight pointLights[MAX_POINT_LIGHTS];
            
uniform sampler2D theTexture;
uniform Material material;

uniform vec3 eyePosition;

vec4 calcLightByDirection(Light light, vec3 direction)
{
    vec4 ambientColour = vec4(light.colour, 1.0f) * light.ambientIntensity;
    
    	float diffuseFactor = max(dot(normalize(Normal), normalize(light.direction)), 0.0f);
	vec4 diffuseColour = vec4(light.colour, 1.0f) * light.diffuseintensity * diffuseFactor;

	vec4 specularColour = vec4(0, 0, 0, 0);

	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);	
		vec3 reflectedVertex = normalize(reflect(light.direction, normalize(Normal)));

		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(light.colour * material.specularIntensity * specularFactor, 1.f);
		}
	}

	return (ambientColour + diffuseColour + specularColour);
}

void main()			
{
	vec4 ambientColour = vec4(directionalLight.colour, 1.0f) * directionalLight.ambientIntensity;
    
    	float diffuseFactor = max(dot(normalize(Normal), normalize(directionalLight.direction)), 0.0f);
	vec4 diffuseColour = vec4(directionalLight.colour, 1.0f) * directionalLight.diffuseintensity * diffuseFactor;

	vec4 specularColour = vec4(0, 0, 0, 0);

	if(diffuseFactor > 0.0f)
	{
		vec3 fragToEye = normalize(eyePosition - FragPos);	
		vec3 reflectedVertex = normalize(reflect(directionalLight.direction, normalize(Normal)));

		float specularFactor = dot(fragToEye, reflectedVertex);
		if(specularFactor > 0.0f)
		{
			specularFactor = pow(specularFactor, material.shininess);
			specularColour = vec4(directionalLight.colour * material.specularIntensity * specularFactor, 1.f);
		}
	}

	colour = texture(theTexture, TexCoord) * (ambientColour + diffuseColour + specularColour);
	//colour = texture(theTexture, TexCoord) * vCol;
}