#ifndef _GLHLIB_H_
#define _GLHLIB_H_

#include <GL\GL.h>

/* Graphics Library Helper aka glh
** This is version 1.62
** The latest can be found at
** http://www.geocities.com/vmelkon/glhlibrary.html
** By Vrej Melkonian
** vmelkon@yahoo.com
** Copyright (C) 2001-2008 Vrej Melkonian All Rights Reserved.
**
** The Readme.txt file that comes with the ZIP file (glhlib_161.zip) contains
** some information as to how to use this library. Description of each function
** is given below.
**
** The Copyright.txt file that comes with the ZIP file (glhlib_161.zip) contains
** some legal information about this library.
**
** This library is updated often on my own machine, as the need arises
** so updates are not regularly available on the web page.
** Updates to the web page are only made when a significant amount
** of new functionality is added.
*/



#define GLH_ALIGN16 __declspec(align(16))


/*Global stuff*/
#ifndef NULL
#define NULL		0
#endif


#ifdef __cplusplus
extern "C"{
#endif


#define GLHLIB_API _stdcall

/*Defines -start*/

/*Part 1*/
#define GLH_ENGLISH							0x000186A0

#define GLH_GLHLIB_VERSION					0x000186A0
#define GLH_GLHLIB_URL						0x000186A2
#define GLH_GLHLIB_DESCRIBE					0x000186A3
#define GLH_OPENGL_VERSION					0x000186A4
#define GLH_OPENGL_SUBVERSION				0x000186A5
#define GLH_OPENGL_DRIVERVERSION			0x000186A6
#define GLH_GLSL_VERSION					0x000186A7
#define GLH_OPENGL_HARDWAREACCELERATION		0x000186A8
#define GLH_GPU_SHADERMODEL					0x000186A9
#define GLH_VENDOR							0x000186AA


//glhGetIntegerv(GLH_VENDOR, params) returns one of these in params
#define VENDOR_UNKNOWN						0x000000000
#define VENDOR_ATI							0x000000001			//ATI and AMD are the same
#define VENDOR_NVIDIA						0x000000002
#define VENDOR_INTEL						0x000000003
#define VENDOR_SIS							0x000000004
#define VENDOR_3DFX							0x000000005
#define VENDOR_3DLABS						0x000000006
#define VENDOR_MESA							0x000000007
#define VENDOR_DIAMONDMULTIMEDIA			0x000000008
#define VENDOR_XGI							0x000000009
#define VENDOR_ELSA							0x00000000A
#define VENDOR_IMAGINATIONTECHNOLOGIES		0x00000000B
#define VENDOR_MATROX						0x00000000C
#define VENDOR_MICROSOFT					0x00000000D
#define VENDOR_S3							0x00000000E


/*Part 2*/
#define GLH_ERROR_NONE						0xF0000000
#define GLH_ERROR_OUT_OF_MEMORY				0xF0000001
#define GLH_ERROR_INVALID_PARAM				0xF0000002
#define GLH_ERROR_INVALID_INDEX				0xF0000003
#define GLH_ERROR_INVALID_ID				0xF0000004
#define GLH_ERROR_INVALID_VALUE				0xF0000005
#define GLH_ERROR_STACK_OVERFLOW			0xF0000006
#define GLH_ERROR_STACK_UNDERFLOW			0xF0000007
#define GLH_ERROR_INTERNALERROR				0xF0000008


#define GLH_MODE_NONE						0x01000000
#define GLH_MODE_STANDARD					0x0100000F
#define GLH_MODE_ALTERNATE					0x010000F0
#define GLH_MODE_ALTERNATE2					0x010000F1
#define GLH_MODE_ALTERNATE3					0x010000F2
#define GLH_MODE_ALTERNATE4					0x010000F3
#define GLH_INTERPOLATIONQUALITY_LINEAR		0xF0000001
#define GLH_INTERPOLATIONQUALITY_COS		0xF0000002

#define GLH_OPTIMIZE_NONE					0x00100000
#define GLH_OPTIMIZE_MMX_SSE				0x0010000F


//Direct3D : pixels shader
#define	GLH_SHADERTYPE_PS_1_1			0x02000001
#define	GLH_SHADERTYPE_PS_1_2			0x02000002
#define	GLH_SHADERTYPE_PS_1_3			0x02000003
#define	GLH_SHADERTYPE_PS_1_4			0x02000004
#define	GLH_SHADERTYPE_PS_2_0			0x0200000A
#define	GLH_SHADERTYPE_PS_2_X			0x0200000B
#define	GLH_SHADERTYPE_PS_2_A			0x0200000C
#define	GLH_SHADERTYPE_PS_2_SW			0x0200000D
#define	GLH_SHADERTYPE_PS_3_0			0x02000020
#define	GLH_SHADERTYPE_PS_3_SW			0x02000021

//Direct3D : vertex shader
#define	GLH_SHADERTYPE_VS_1_1			0x03000001
#define	GLH_SHADERTYPE_VS_1_2			0x03000002
#define	GLH_SHADERTYPE_VS_1_3			0x03000003
#define	GLH_SHADERTYPE_VS_1_4			0x03000004
#define	GLH_SHADERTYPE_VS_2_0			0x0300000A
#define	GLH_SHADERTYPE_VS_2_X			0x0300000B
#define	GLH_SHADERTYPE_VS_2_A			0x0300000C
#define	GLH_SHADERTYPE_VS_2_SW			0x0300000D
#define	GLH_SHADERTYPE_VS_3_0			0x03000020
#define	GLH_SHADERTYPE_VS_3_SW			0x03000021

//OpenGL : ASM vertex program
#define GLH_SHADERTYPE_ARBVP_1_0		0x03000010

//OpenGL : ASM fragment program
#define GLH_SHADERTYPE_ARBFP_1_0		0x02000010

//OpenGL : GLSL vertex shader
#define GLH_SHADERTYPE_GLSL_VS_1_00		0x04000000

//OpenGL : GLSL fragment shader
#define GLH_SHADERTYPE_GLSL_FS_1_00		0x04000001



#define GLH_INDEX_OF_REFRACTION_VACUUM				1.0
#define GLH_INDEX_OF_REFRACTION_AIR					1.000293
#define GLH_INDEX_OF_REFRACTION_ICE					1.31
#define GLH_INDEX_OF_REFRACTION_WATER				1.333333
#define GLH_INDEX_OF_REFRACTION_ETHYLALCOHOL		1.36
#define GLH_INDEX_OF_REFRACTION_FLUORITE			1.43
#define GLH_INDEX_OF_REFRACTION_POPPYSEEDOIL		1.469
#define GLH_INDEX_OF_REFRACTION_OLIVEOIL			1.47
#define GLH_INDEX_OF_REFRACTION_LINSEEDOIL			1.478
#define GLH_INDEX_OF_REFRACTION_PLEXIGLASS			1.51
#define GLH_INDEX_OF_REFRACTION_IMMERSIONOIL		1.515
#define GLH_INDEX_OF_REFRACTION_CROWNGLASS			1.52
#define GLH_INDEX_OF_REFRACTION_QUARTZ				1.54
#define GLH_INDEX_OF_REFRACTION_SODIUMCHLORIDE		1.54
#define GLH_INDEX_OF_REFRACTION_LIGHTFLINTGLASS		1.58
#define GLH_INDEX_OF_REFRACTION_DENSEFLINTGLASS		1.66
#define GLH_INDEX_OF_REFRACTION_TOURMALINE			1.62
#define GLH_INDEX_OF_REFRACTION_GARNET				1.73
#define GLH_INDEX_OF_REFRACTION_ZIRCON				1.923
#define GLH_INDEX_OF_REFRACTION_CUBICZIRCONIA		2.14
#define GLH_INDEX_OF_REFRACTION_DIAMOND				2.417
#define GLH_INDEX_OF_REFRACTION_RUTILE				2.907
#define GLH_INDEX_OF_REFRACTION_GALLIUMPHOSPHIDE	3.5





#define GLH_UP										0x00000001
#define GLH_DOWN									0x00000002
#define GLH_LEFT									0x00000004
#define GLH_RIGHT									0x00000008



//PURPOSE:	For indices, if we want GLushort or GLuint
enum GLH_INDEXFORMAT
{
	GLH_INDEXFORMAT_16BIT,		//GLushort
	GLH_INDEXFORMAT_32BIT		//GLuint
};

//PURPOSE:	Some predefined vertex formats and following it are some struct that go along with it
enum GLHVERTEXFORMAT
{
	GLHVERTEXFORMAT_NULL,
	GLHVERTEXFORMAT_V,				//Only vertex, xyz
	GLHVERTEXFORMAT_VT,				//xyz, st
	GLHVERTEXFORMAT_VNT,			//xyz, nxnynz, st
	GLHVERTEXFORMAT_VNT3,			//xyz, nxnynz, str
	GLHVERTEXFORMAT_VNTT3T3			//xyz, nxnynz, st, tangent(xyz), binormal (xyz)
};


//Vertex
//SIZE : 4+4+4 = 4*3 = 12 bytes
//It's better to make it multiple of 32
//32-12 = 20 bytes (of garbage should be added)
//20/4 = 5 floats should be added
struct GLHVertex_V
{
	GLfloat	x, y, z;
	GLfloat	garbage[5];
};


//Vertex, tex0
//
//SIZE : 4+4+4 +4+4 = 4*6 = 20 bytes
//It's better to make it multiple of 32
//32-20 = 12 bytes (of garbage should be added)
//12/4 = 3 floats should be added
struct GLHVertex_VT
{
	GLfloat	x, y, z;
	GLfloat	s, t;
	GLfloat	garbage[3];
};

//Vertex, normal, tex0
//
//SIZE : 4+4+4 +4+4+4 +4+4 = 4*8 = 32 bytes
struct GLHVertex_VNT
{
	GLfloat	x, y, z;
	GLfloat	nx, ny, nz;
	GLfloat	s, t;
};

//Vertex, normal, tex0
//
//SIZE : 4+4+4 +4+4+4 +4+4+4 = 4*9 = 36 bytes
//It's better to make it multiple of 32
//32+32 = 64 bytes
//64-36 = 28 bytes (of garbage should be added)
//28/4 = 7 floats should be added
struct GLHVertex_VNT3
{
	GLfloat	x, y, z;
	GLfloat	nx, ny, nz;
	GLfloat	s, t, r;
	GLfloat	garbage[7];
};


//Vertex, normal, tex0, tex1, tex2
//
//SIZE : 4+4+4 +4+4+4 +4+4 +4+4+4 +4+4+4 = 4*14 = 56 bytes
//It's better to make it multiple of 32
//32+32 = 64
//64-56 = 8 bytes (of garbage should be added)
//8/4 = 2 floats should be added
struct GLHVertex_VNTT3T3
{
	GLfloat	x, y, z;
	GLfloat	nx, ny, nz;
	GLfloat	s, t;
	GLfloat	s2, t2, r2;
	GLfloat	s3, t3, r3;
	GLfloat	garbage[2];
};







//PURPOSE:	Get GL 1.5 capabilities.
//			See function glhGetGLDeviceCaps_GL_1_5 on this page.
struct GLCAPS_GL_1_5
{
	GLint	Size;							//The size of this struct

	//Buffers
	GLboolean	RGBAModeb;
	GLboolean	DoubleBufferedb;
	GLint		AuxBufferCounti;
	GLboolean	Stereob;
	GLint		RedBitsi;				//Main plain (back buffer in case of double buffering or front buffer in case of single buffering)
	GLint		GreenBitsi;
	GLint		BlueBitsi;
	GLint		AlphaBitsi;
	GLint		DepthBitsi;
	GLint		StencilBitsi;
	GLint		AccumRedBitsi;
	GLint		AccumGreenBitsi;
	GLint		AccumBlueBitsi;
	GLint		AccumAlphaBitsi;

	//Clip plane
	GLint	MaxClipPlanesi;

	//Matrices and stacks
	GLint	MaxModelviewStackDepthi;
	GLint	MaxProjectionStackDepthi;
	GLint	MaxTextureStackDepthi;
	GLint	MaxNameStackDepthi;
	GLint	MaxListNestingi;
	GLint	MaxEvalOrderi;
	GLint	MaxAttribStackDepthi;
	GLint	MaxClientAttribStackDepthi;

	//Pixel and fragments
	GLint	SubPixelBitsi;
	GLint	Samplesi;						//Coverage mask size
	GLint	SampleBuffersi;					//Number if multisample buffers
	GLint	QueryCounterBitsi;

	//Textures
	GLint	MaxTexture1DSizei;				//One value for width
	GLint	MaxTexture2DSizei;				//One value for both width and height
	GLint	MaxTexture3DSizei;				//One value for both width and height and depth
	GLint	MaxTextureCubeSizei;			//One value for both width and height
	GLint	MaxTextureLODBiasi;
	GLint	MaxTextureUnitsi;
	GLint	CompressedTextureFormatsi;
	GLint	NumberOfCompressedTextureFormatsi;

	//Viewport
	GLint	MaxViewportDimensionsi[2];		//Width, height

	//Primitives
	GLfloat	AliasedPointSizeRangef[2];		//Smallest and largest
	GLfloat	SmoothPointSizeRangef[2];		//Smallest and largest
	GLfloat	AliasedLineWidthRangef[2];		//Smallest and largest
	GLfloat	SmoothLineWidthRangef[2];		//Smallest and largest

	//Arrays
	GLint	MaxElementsIndicesi;
	GLint	MaxElementsVerticesi;

	//Lights
	GLint	MaxLightsi;
};


//PURPOSE:	Get GL 2.0 capabilities.
//			See function glhGetGLDeviceCaps_GL_2_0 on this page.
struct GLCAPS_GL_2_0 : public GLCAPS_GL_1_5
{
	//Vertex related
	GLint	MaxVertexAttribsi;

	//Texture related
	GLint	MaxCombinedTextureImageUnitsi;
	GLint	MaxTextureImageUnitsi;
	GLint	MaxTextureCoordsi;
};

//PURPOSE:	Get information about GL_ARB_vertex_program
//			See function glhGetGLDeviceCaps_ARB_vp_1_0 on this page.
struct GLCAPS_ARB_vp_1_0
{
	GLint	Size;							//The size of this struct

	GLint	MaxProgramInstructionsVPi;
	GLint	MaxProgramNativeInstructionsVPi;
	GLint	MaxProgramTemporariesVPi;
	GLint	MaxProgramNativeTemporariesVPi;
	GLint	MaxProgramParametersVPi;
	GLint	MaxProgramNativeParametersVPi;
	GLint	MaxProgramAttribsVPi;
	GLint	MaxProgramNativeAttribsVPi;
	GLint	MaxProgramAddressRegistersVPi;
	GLint	MaxProgramNativeAddressRegistersVPi;
	GLint	MaxProgramLocalParametersVPi;
	GLint	MaxProgramEnvParametersVPi;
	GLint	MaxVertexAttribsi;
	GLint	MaxProgramMatricesi;
	GLint	MaxProgramMatrixStackDepthi;
};

//PURPOSE:	Get information about GL_ARB_fragment_program
//			See function glhGetGLDeviceCaps_ARB_fp_1_0 on this page.
struct GLCAPS_ARB_fp_1_0
{
	GLint	Size;							//The size of this struct

	GLint	MaxProgramInstructionsFPi;
	GLint	MaxProgramNativeInstructionsFPi;
	GLint	MaxProgramTemporariesFPi;
	GLint	MaxProgramNativeTemporariesFPi;
	GLint	MaxProgramParametersFPi;
	GLint	MaxProgramNativeParametersFPi;
	GLint	MaxProgramAttributesFPi;
	GLint	MaxProgramNativeAttributesFPi;
	GLint	MaxProgramEnvParametersFPi;
	GLint	MaxProgramALUInstructionsFPi;
	GLint	MaxProgramNativeALUInstructionsFPi;
	GLint	MaxProgramTEXInstructionsFPi;
	GLint	MaxProgramNativeTEXInstructionsFPi;
	GLint	MaxProgramTEXIndirectionsFPi;
	GLint	MaxProgramNativeTEXIndirectionsFPi;
	GLint	MaxProgramMatricesi;
	GLint	MaxProgramMatrixStackDepthi;
	GLint	MaxTextureCoordsi;
	GLint	MaxTextureImageUnitsi;
};


//PURPOSE:	Get information about GL 2.0 (and above) GLSL
//			See function glhGetGLDeviceCaps_GL2_0_GLSL on this page.
struct GLCAPS_GL_2_0_GLSL
{
	GLint	Size;

	char	ShadingLanguageVersionc[64];	//String GLSL version returned by glGetString
	GLfloat	ShadingLanguageVersionf;		//Float GLSL version. Same value as returned by glhGetGLSLMainVersion

	GLint	MaxVertexUniformComponentsi;
	GLint	MaxVertexTextureImageUnitsi;
	GLint	MaxFragmentUniformComponentsi;
	GLint	MaxVaryingFloatsi;
	
};


/*Defines -end*/

/*Block 0 -start*/

//PURPOSE:	With the new features added in glh, we need a init, shutdown and geterror functions.
//glhGetError and glhCopyErrorInto_cBuffer appear in Block 14
void GLHLIB_API glhInitLibrary();
void GLHLIB_API glhShutDownLibrary();

/*Block 0 -end*/


/*Block 1 -start*/
//****************************************************************************
//THIS IS THE INFORMATION BLOCK.
//Collect information on glh, glu, GL, GL ES.
//The glh project will either be compiled for GL or GL ES.

//PURPOSE:	Get some info about the glh library. See section Defines Part 1
//
//			**** Note : glhGetOpenGLMainVersionAsString has been deleted. Use glhGetString(GLH_ENGLISH, GLH_OPENGL_VERSION)
//			            glhGetOpenGLSubVersionAsString has been deleted. Use glhGetString(GLH_ENGLISH, GLH_OPENGL_SUBVERSION)
//			            glhGetOpenGLDriverVersionAsString has been deleted. Use glhGetString(GLH_ENGLISH, GLH_OPENGL_DRIVERVERSION)
//			            glhGetGLSLMainVersionAsString has been deleted. Use glhGetString(GLH_ENGLISH, GLH_GLSL_VERSION)
//
//PARAMETERS:
//			[in] language: GLH_ENGLISH
//			[in] token:	GLH_GLHLIB_VERSION, GLH_GLHLIB_URL, GLH_GLHLIB_DESCRIBE
//			            GLH_OPENGL_VERSION : If glGetString(GL_VERSION) returns "1.3.1", this will return "1.3"
//			            GLH_OPENGL_SUBVERSION : If glGetString(GL_VERSION) returns "1.3.1", this function will return "1"
//			            GLH_OPENGL_DRIVERVERSION : Gets the OpenGL driver version and copies into buffer.
//			            buffer is a NULL string if something goes wrong.
//			            This function calls glGetString(GL_VERSION)
//			            and expects the version number to come after the OpenGL
//			            version number. Example :  1.2.1 34.56.12 so driver version is 34.56.12
//			            Some vendors do not provide the driver version so this will return
//			            an empty string in those cases.
//			            GLH_GLSL_VERSION : If glGetString(GL_SHADING_LANGUAGE_VERSION) returns "1.3.1", this function will return "1.3"
//			            GLH_GPU_SHADERMODEL : This is a hack and might change in the future. Most GL programmers want to ID the GPU
//			            and I think it's a good idea to be able to do so.
//			            This function tries to guess the Shader Model (SM) supported by the GPU.
//			            It checks for the presence of the extension GL_NV_vertex_program3, which would
//			            mean SM 3.0 for NV hw.
//			            It checks for the presence of GL_ATI_shader_texture_lod, which would mean SM 3.0 for ATI hw.
//			            If those extensions are not found, the code assumes you have SM 2.0
//			            It does not check to see if GL 2.0 is supported.
//			            It does not check for GL_ARB_shading_language_100 and the others.
//			            **** You might also be interested in glhGetIntegerv(GLH_VENDOR, params) ****
//
//			Update : The Geforce 8800 introduced a whole set of extensions, so if GL_EXT_gpu_shader4
//			         is found, you have a SM 4.0 GPU
//
//
//RETURN:
//			Pointer to constant string if valid language and token, else NULL.
const char* GLHLIB_API glhGetString(GLenum language, GLenum token);


//PURPOSE:	Get some info about the glh library. See section Defines Part 1
//			**** With some of the pnames, you get a single value, in others major and minor number.
//
//			**** Note : glhGetOpenGLMainVersion has been deleted. Use glhGetIntegerv(GLH_OPENGL_VERSION, params)
//			            glhGetGLSLMainVersion has been deleted. Use glhGetIntegerv(GLH_GLSL_VERSION, params)
//			            glhGetShaderModel has been deleted. Use glhGetIntegerv(GLH_GPU_SHADERMODEL, params)
//			            glhIsRunningInHardwareMode has been deleted. Use glhGetIntegerv(GLH_OPENGL_HARDWAREACCELERATION, params)
//
//PARAMETERS:
//			[in] pname:	GLH_GLHLIB_VERSION, then params will be the major and minor version
//
//			            GLH_OPENGL_HARDWAREACCELERATION : To find out if we are running in software or hardware mode.
//			            In other words, are we running using an ICD or MCD mechanism
//			            or Windows GDI. It works by checking if the first 3 letters is GDI.
//			            It searches for the word MESA (Mesa), since MESA is software on Windows.
//			            It searches for the word Direct3D (Direct 3D), since Direct3D is considered
//			            a software solution.
//			            Returns 1 for YES and 0 for NO
//			            GLH_OPENGL_VERSION returns major and minor GL version
//			            GLH_GLSL_VERSION returns major and minor GLSL version
//			            This is a hack and might change in the future. Most GL programmers want to ID the GPU
//			            and I think it's a good idea to be able to do so.
//			            GLH_GPU_SHADERMODEL : returns major and minor version.
//			            Tries to guess the Shader Model (SM) supported by the GPU.
//			            It checks for the presence of the extension GL_NV_vertex_program3, which would
//			            mean SM 3.0 for NV hw.
//			            It checks for the presence of GL_ATI_shader_texture_lod, which would mean SM 3.0 for ATI hw.
//			            If those extensions are not found, the code assumes you have SM 2.0
//			            It does not check to see if GL 2.0 is supported.
//			            It does not check for GL_ARB_shading_language_100 and the others.
//			            **** You might also be interested in glhGetIntegerv(GLH_VENDOR, params) ****
//
//			            Update : The Geforce 8800 introduced a whole set of extensions, so if GL_EXT_gpu_shader4
//			            is found, you have a SM 4.0 GPU
//
//			            GLH_VENDOR : returns some ID like VENDOR_UNKNOWN, VENDOR_ATI, VENDOR_NVIDIA, VENDOR_INTEL
//
//			[out] params : returns integers based on what you supply to pname
void GLHLIB_API glhGetIntegerv(GLenum pname, GLint *params);


//PURPOSE:	Call this function to get GL 1.5 device capabilities
//
//PARAMETERS:
//			[out] errorMessage : If error occurs, a message is written here. Can be NULL.
//			                     Should be at least 512 bytes large.
//			[in] adapterCount : unused
//			[in] deviceType : unused
//			[in, out] pcaps : pointer to GLCAPS_GL_1_5
//			                  pcaps->Size must be sizeof(GLCAPS_GL_1_5)
//
//RETURN:
//			1 for success
//			-1 for error plus message.
GLint GLHLIB_API glhGetGLDeviceCaps_GL_1_5(char *errorMessage, GLint adapterCount, GLint deviceType, GLCAPS_GL_1_5 *pcaps);

//PURPOSE:	Call this function to get GL 2.0 device capabilities
//			You might also want to call glhGetGLDeviceCaps_GL2_0_GLSL to get GLSL related variables.
//
//PARAMETERS:
//			[out] errorMessage : If error occurs, a message is written here. Can be NULL.
//			                     Should be at least 512 bytes large.
//			[in] adapterCount : unused
//			[in] deviceType : unused
//			[in, out] pcaps : pointer to GLCAPS_GL_2_0
//			                  pcaps->Size must be sizeof(GLCAPS_GL_2_0)
//
//RETURN:
//			1 for success
//			-1 for error plus message.
GLint GLHLIB_API glhGetGLDeviceCaps_GL_2_0(char *errorMessage, GLint adapterCount, GLint deviceType, GLCAPS_GL_2_0 *pcaps);

//PURPOSE:	In the same spirit as glhGetGLDeviceCaps_GL_1_5, this gets specific information
//			about the GL_ARB_vertex_program extension.
//			**** This will call wglGetProcAddress to get pointer to glGetProgramivARB ****
//
//PARAMETERS:
//			[out] errorMessage : If error occurs, a message is written here. Can be NULL.
//			                     Should be at least 512 bytes large.
//			[in] adapterCount : unused
//			[in] deviceType : unused
//			[in, out] pcaps : pointer to GLCAPS_ARB_vp_1_0
//			                  pcaps->Size must be sizeof(GLCAPS_ARB_vp_1_0)
//
//RETURN:
//			1 for success
//			-1 for error plus message.
GLint GLHLIB_API glhGetGLDeviceCaps_ARB_vp_1_0(char *errorMessage, GLint adapterCount, GLint deviceType, GLCAPS_ARB_vp_1_0 *pcaps);


//PURPOSE:	In the same spirit as glhGetGLDeviceCaps_GL_1_5, this gets specific information
//			about the GL_ARB_fragment_program extension.
//			**** This will call wglGetProcAddress to get pointer to glGetProgramivARB ****
//
//PARAMETERS:
//			[out] errorMessage : If error occurs, a message is written here. Can be NULL.
//			                     Should be at least 512 bytes large.
//			[in] adapterCount : unused
//			[in] deviceType : unused
//			[in, out] pcaps : pointer to GLCAPS_ARB_fp_1_0
//			                  pcaps->Size must be sizeof(GLCAPS_ARB_fp_1_0)
//
//RETURN:
//			1 for success
//			-1 for error plus message.
GLint GLHLIB_API glhGetGLDeviceCaps_ARB_fp_1_0(char *errorMessage, GLint adapterCount, GLint deviceType, GLCAPS_ARB_fp_1_0 *pcaps);


//PURPOSE:	Make sure GL 2.0 and above is supported before calling this.
//
//PARAMETERS:
//			[out] errorMessage : If error occurs, a message is written here. Can be NULL.
//			                     Should be at least 512 bytes large.
//			[in] adapterCount : unused
//			[in] deviceType : unused
//			[in, out] pcaps : pointer to GLCAPS_GL_2_0_GLSL
//			                  pcaps->Size must be sizeof(GLCAPS_GL_2_0_GLSL)
//
//RETURN:
//			1 for success
//			-1 for error plus message.
GLint GLHLIB_API glhGetGLDeviceCaps_GL2_0_GLSL(char *errorMessage, GLint adapterCount, GLint deviceType, GLCAPS_GL_2_0_GLSL *pcaps);


//PURPOSE:	Check to see if an extension is present in glGetString(GL_EXTENSIONS)
//
//PARAMETERS:
//			extensionName : Something like GL_ARB_multitexture
//
//RETURN:
//			TRUE or FALSE
//			-1 if glGetString(GL_EXTENSIONS) returns NULL.
GLint GLHLIB_API glhIsGLExtensionSupported(const char *extensionName);

//PURPOSE:	Check to see if an extension is present in wglGetExtensionsStringARB(hdc) or wglGetExtensionsStringEXT(hdc)
//			Uses the ARB version if present, and failing that, uses EXT version, and failing that, it returns -1.
//
//PARAMETERS:
//			extensionName : Something like WGL_EXT_swap_control
//
//RETURN:
//			TRUE or FALSE
//			-1 if wglGetExtensionsStringARB(hdc) or wglGetExtensionsStringEXT(hdc) returns NULL.
//			-1 if neither function is present.
GLint GLHLIB_API glhIsWGLExtensionSupported(HDC hdc, const char *extensionName);


//PURPOSE:	Try to get the OpenGL error and copy it into the pstring.
//			Returns 1 if pstring==NULL
//			Returns 1 if no errors found, else it returns -1.
//NOTE:		Even if there is an error, pstring may be strlen(pstring)==0 if
//			error was not identified.
//UPDATE:	Sunday, March 13, 2005 : Error code added for GL_EXT_framebuffer_object (GL_INVALID_FRAMEBUFFER_OPERATION_EXT)
GLint GLHLIB_API glhCopyOpenGLErrorInto_cBuffer(char *pstring);

/*Block 1 -end*/


/*Block 2 -start*/
//****************************************************************************
//TEXTURE SCALING OPERATIONS. DONE IN SOFTWARE.

//PURPOSE:	This function will not verify if values being passed are valid.
//			format must be RGB888 or RGBA8888 (GL_RGB, GL_RGB8, GL_RGBA, GL_RGBA8 are all accepted)
//			If isUseLinearOrPointSample=GL_TRUE then linear filtering is used else if GL_FALSE
//			point sampling is used.
//			dataAlignment must be 1 or 4.
//			Returns 1 if success. 0 for failure, -5 for not yet implemented.
//MESSAGE:	Only use glhScaleImage_asm386 in your important apps. The MMX version was a test
//			version and is slower (Intel didn't design MMX intelligently).
//			glhScaleImage2_asm386 is a test version and has bugs.
GLint GLHLIB_API glhScaleImage_asm386(GLenum format, GLboolean isUseLinearOrPointSample,
		GLint dataAlignment,
		GLint widthin, GLint heightin,
		GLubyte *datain,
		GLint widthout, GLint heightout,
		GLubyte *dataout);

//PURPOSE:	Similar to glhScaleImage_asm386, except that we also scale in the z-direction (r-direction)
//			if needed. This function makes extensive use of glhScaleImage_asm386.
//
//			This function will not verify if values being passed are valid.
//			format must be RGB888 or RGBA8888 (GL_RGB, GL_RGB8, GL_RGBA, GL_RGBA8 are all accepted)
//			If isUseLinearOrPointSample=GL_TRUE then linear filtering is used else if GL_FALSE
//			point sampling is used.
//			dataAlignment must be 1 or 4.
//			Returns 1 if success. 0 for failure, -5 for not yet implemented.
GLint GLHLIB_API glhScaleImage3D_asm386(GLenum format, GLboolean isUseLinearOrPointSample,
		GLint dataAlignment,
		GLint widthin, GLint heightin, GLint depthin,
		GLubyte *datain,
		GLint widthout, GLint heightout, GLint depthout,
		GLubyte *dataout);

//MESSAGE:	Only use glhScaleImage_asm386 in your important apps. The MMX version was a test
//			version and is slower (Intel didn't design MMX intelligently).
//			glhScaleImage2_asm386 is a test version and has bugs.
GLint GLHLIB_API glhScaleImage_asm386_MMX(GLenum format, GLboolean isUseLinearOrPointSample,
		GLint dataAlignment,
		GLint widthin, GLint heightin,
		GLubyte *datain,
		GLint widthout, GLint heightout,
		GLubyte *dataout);

//PURPOSE:	This function will not verify if values being passed are valid.
//			format must be RGB888 or RGBA8888 (GL_RGB, GL_RGB8, GL_RGBA, GL_RGBA8 are all accepted)
//			If isUseLinearOrPointSample=GL_TRUE then linear filtering is used else if GL_FALSE
//			point sampling is used.
//			dataAlignment must be 1.
//			Returns 1 if success. 0 for failure, -5 for not yet implemented.
//MESSAGE:	Only use glhScaleImage_asm386 in your important apps. The MMX version was a test
//			version and is slower (Intel didn't design MMX intelligently).
//			glhScaleImage2_asm386 is a test version and has bugs.
GLint GLHLIB_API glhScaleImage2_asm386(GLenum format, GLboolean isUseLinearOrPointSample,
		GLint dataAlignment,
		GLint widthin, GLint heightin,
		GLubyte *datain,
		GLint widthout, GLint heightout,
		GLubyte *dataout);

/*Block 2 -end*/

/*Block 3 -start*/
//****************************************************************************
//TEXTURE MIPMAP GENERATION AND UPLOAD T OPENGL
//Some functions that are similar to gluBuild2DMipmaps and extra things.

//PURPOSE:	This function will copy the pixels pointed to by pixels into the level=0 and
//			will use glhScaleImage_asm386() to scale the pixels and use them to update all the
//			other mipmaps. The application is responsable for knowing if mipmapping is used.
//			textureWidth and textureHeight are the width and height of the entire texture.
//			The other parameters are the same as glTexSubImage2D().
//			format must be GL_RGB or GLRGB8 or GL_RGBA or GL_RGBA8. type must be GL_UNSIGNED_BYTE.
//			Make sure glPixelStorei(GL_UNPACK_ALIGNMENT, 1 or 4); before calling this.
//			and dataAlignment must be 1 or 4
void GLHLIB_API glhTexSubImage2DMipmaps(GLint xoffset,
								GLint yoffset, GLsizei width, GLsizei height,
								GLsizei textureWidth, GLsizei textureHeight,
								GLenum format,
								GLenum type, const GLvoid *pixels);

//PURPOSE:	This function will build all the mipmaps using glhScaleImage_asm386() available
//			in this library.
//			components must be the same as for glTexImage2D.
//			dataAlignment must be 1 or 4, so be sure to call glPixelStorei(GL_UNPACK_ALIGNMENT, 1 or 4)
//			before using this function.
//			width and height must be positive, this function will not check for that.
//			If isPromoteToHigherPowerOn==GL_TRUE, then width and height will be bumped up to
//			next power of 2 number if not already power of 2, else if GL_FALSE they get bumped down
//			to a power of 2 number if not already power of 2.
//			format must be GL_RGB for RGB888 or GL_RGBA for RGBA8888 (or GL_BGR or GL_BGRA or GL_ABGR_EXT)
//			data must be of type unsigned char (GLubyte)
//			Returns 0 for memory error, 1 for success, -5 for not yet implemented, -1 for misuse
//WARNING:	The contents of data will be changed, but the pointer will remain the same.
//			**** That used to be true for version 1.3 and below, but no longer ****
GLint GLHLIB_API glhBuild2DMipmaps(GLint components, GLint dataAlignment, GLint width, GLint height,
				GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *data);

//PURPOSE:	This function will build all the mipmaps using glhScaleImage_asm386()
//			and will upload it to OpenGL, very much like gluBuild2DMipmaps for 2D textures.
//			This function does it for cubemaps
//
//PARAMETERS:
//			[in] components : must be the same as for glTexImage2D.
//			[in] dataAlignment : must be 1 or 4, so be sure to call glPixelStorei(GL_UNPACK_ALIGNMENT, 1 or 4)
//			                     before using this function.
//			[in] width : must be positive, this function will not check for that.
//			[in] height : must be positive, this function will not check for that.
//			[in] isPromoteToHigherPowerOn : if GL_TRUE, then width and height will be bumped up to
//			                                next power of 2 number if not already power of 2, else if GL_FALSE
//			                                they get bumped down to a power of 2 number if not already power of 2.
//			[in] format : must be GL_RGB for RGB888 or GL_RGBA for RGBA8888 (or GL_BGR or GL_BGRA or GL_ABGR_EXT)
//			[in] data : must be of type unsigned char (GLubyte). All the faces of the cubemap must be in sequence
//			            POSX, NEGX, POSY, NEGY, POSZ, NEGZ
//
//RETURN:
//			0 for memory error
//			1 for success
//			-5 for not yet implemented
//			-1 for misuse
GLint GLHLIB_API glhBuildCubeMapMipmaps(GLint components, GLint dataAlignment, GLint width, GLint height,
				GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *data);

//PURPOSE:	This function will build all the mipmaps using glhScaleImage_asm386()
//			in this library.
//			The rest of the parameters are the same as for glhBuildCubeMapMipmaps
//			except for depth, which is required for 3D textures.
//NOTE:		data points to an area of memory containing all the slices for the 3D texture.//NOTE: data points to an area of memory containing all the slices for the 3D texture.
//GLint GLHLIB_API glhBuild3DMipmaps(GLint components, GLint dataAlignment, GLint width, GLint height, GLint depth,
//				GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *data);


//PURPOSE:	For mipmaping normal maps.
//			The standard mipmapping algorithm is not suitable.
//			This will normalize each texel after doing the box filter.
//			It will upload each texture including the base texture to OpenGL
//			so be sure to call glBindTexture(GL_TEXTURE_2D, textureID);
//			before calling this.
//			Returns 0 for memory error, 1 for success, -1 for misuse.
//
//			components must be the same as for glTexImage2D.
//			dataAlignment must be 1 or 4, so be sure to call glPixelStorei(GL_UNPACK_ALIGNMENT, 1 or 4)
//			before using this function.
//			width and height must be power of 2
//			isPromoteToHigherPowerOn is ignored.
//			format must be GL_RGBA for RGBA8888 (or GL_BGRA or GL_ABGR_EXT)
//					we consider R as x, G as y, B as z, A as length of vector
//			data must be of type unsigned char (GLubyte)
//			The level 0 mipmap must be normalized (the RGB) and alpha must be 255 everywhere.
GLint GLHLIB_API glhBuild2DNormalMipmaps(GLint components, GLint dataAlignment, GLint width, GLint height, GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *data);
//PURPOSE:	Similar to glhBuild2DNormalMipmaps, except we have GLfloat instead of GLubyte, in
//			which case for format == GL_RGBA, it is considered as RGBA32-32-32-32.
GLint GLHLIB_API glhBuild2DNormalMipmapsf(GLint components, GLint dataAlignment, GLint width, GLint height,
				GLboolean isPromoteToHigherPowerOn, GLenum format, const GLfloat *data);

//PURPOSE:	Similar to glhBuild2DNormalMipmaps() but data points to 6 faces (similar requirements
//			to glhBuildCubeMapMipmaps)
//			The only difference is that you should call glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
GLint GLHLIB_API glhBuildCubeMapNormalMipmaps(GLint components, GLint dataAlignment, GLint width, GLint height, GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *data);
GLint GLHLIB_API glhBuildCubeMapNormalMipmapsf(GLint components, GLint dataAlignment, GLint width, GLint height,
				GLboolean isPromoteToHigherPowerOn, GLenum format, const GLfloat *data);


//PURPOSE:	This will contruct a cubemap and will write the data into data.
//			After calling this, you might need to call glhBuildCubeMapNormalMipmaps
//			to upload the cubemap to OpenGL and make all the needed mipmaps as well.
//			dataAlignement must be 1 or 4.
//			width and height must be divisible by 2
//			format must be GL_RGBA for RGBA8888 (or GL_BGRA or GL_ABGR_EXT)
//			data must be allocated externally
//			Returns 1 for success, -1 for misuse.
GLint GLHLIB_API glhBuildNormalizationCubeMap(GLint dataAlignment, GLint width, GLint height, GLenum format, GLubyte *data);
GLint GLHLIB_API glhBuildNormalizationCubeMapf(GLint dataAlignment, GLint width, GLint height, GLenum format, GLfloat *data);


/*Block 3 -end*/

/*Block 4 -start*/
//****************************************************************************
//MISCELLANEOUS FUNCTIONS

//PURPOSE:	Random number generator, one for integer (-2^31 to 2^21-1)
//			The other for -1.0 to 1.0
//NOTE:	These functions uses MMX
void GLHLIB_API glhRandomNumberi(GLint *result);
void GLHLIB_API glhRandomNumberf(GLfloat *result);

//PURPOSE:	Compute the Fresnel term depending on incident vector and material index (relative material index)
//			If cosAngle < 0.0, then result receives 0.0 else the fresnel term will be computed.
//			Send an array of values and the output will be an array of values. count is the number of values
//			in cosAngle and the array size of result
//DEFINITION:
//			The Fresnel term is used to compensate for the fact that at high angle, the reflection becomes more
//			pronounced. At 90 degrees, reflection becomes 100% and no light enters the material.
//
//This approximates the fresnel term with the following equation :
//R0 = pow(1 - refractionIndex, 2) / pow(1+refractionIndex, 2)
//
//and
//return R0 + (1-R0) * pow(1-cosAngle, 5);
void GLHLIB_API glhFastFresnelTerm(GLfloat *result, GLfloat *cosAngle, GLfloat refractionIndex, GLint count);

/*Block 4 -end*/

/*Block 5 -start*/
//****************************************************************************
//PERLIN NOISE RELATED

//PURPOSE:	glh stores a table of random number dedicated to the perlin noise
//			generator. If you want new numbers in the table, call this.
void GLHLIB_API glhPerlinRegenerateTable();

//PURPOSE:	Generate a 1D noise function, based on persistence which
//			is defined as
//			frequency = 2^i
//			amplitude = persistence^i
//			in other words ...
//			ln(amplitude) = i*ln(persistence)
//			ln(amplitude)/ln(persistence) = i
//			frequency = 2^ln(amplitude)/ln(persistence)  <----
//
//			The numberOfOctaves which controls how many frequencies to sum up
//			boolOctave is an array the size of numberOfOctaves, with GL_TRUE and GL_FALSE
//			to control which ones to sum up.
//			interpolationQuality should be GLH_INTERPOLATIONQUALITY_LINEAR for low quality
//				GLH_INTERPOLATIONQUALITY_COS for high
//			mode can be GLH_MODE_STANDARD, GLH_MODE_ALTERNATE, GLH_MODE_ALTERNATE2, GLH_MODE_ALTERNATE3, GLH_MODE_ALTERNATE4
//
//			optimize can be GLH_OPTIMIZE_NONE
//
//			posx is 1 float that describes a position in 1D
//
//			The result is a single float and is written to *result.
//
//			Returns 1 for sucess, -1 if bad parameter passed		
GLint GLHLIB_API glhPerlinNoise1D(GLfloat *result, GLint interpolationQuality, GLint mode, GLint optimize, GLfloat posx, GLfloat persistence, GLint numberOfOctaves, GLint *boolOctave);

//PURPOSE:	Generate a 2D noise function, based on persistence which
//			is defined as
//			frequency = 2^i
//			amplitude = persistence^i
//			in other words ...
//			ln(amplitude) = i*ln(persistence)
//			ln(amplitude)/ln(persistence) = i
//			frequency = 2^ln(amplitude)/ln(persistence)  <----
//
//			The numberOfOctaves which controls how many frequencies to sum up
//			boolOctave is an array the size of numberOfOctaves, with GL_TRUE and GL_FALSE
//			to control which ones to sum up.
//			interpolationQuality should be GLH_INTERPOLATIONQUALITY_LINEAR for low quality
//				GLH_INTERPOLATIONQUALITY_COS for high
//			mode can be GLH_MODE_STANDARD, GLH_MODE_ALTERNATE, GLH_MODE_ALTERNATE2, GLH_MODE_ALTERNATE3, GLH_MODE_ALTERNATE4
//			optimize can be GLH_OPTIMIZE_NONE or GLH_OPTIMIZE_MMX_SSE
//
//			pos is 2 floats that describe a position in 2D when optimize == GLH_OPTIMIZE_NONE
//			when optimize == GLH_OPTIMIZE_MMX_SSE, pos is 2*4 floats (xy, xy, xy, xy)
//
//			The result is a single float and is written to *result when optimize == GLH_OPTIMIZE_NONE
//			when optimize == GLH_OPTIMIZE_MMX_SSE, result is 4 floats.
//
//			Returns 1 for sucess, -1 if bad parameter passed
//NOTE:		The only part that uses MMX and SSE when optimize == GLH_OPTIMIZE_MMX_SSE
//			is (interpolationQuality == GLH_INTERPOLATIONQUALITY_LINEAR) && (mode == GLH_MODE_STANDARD)
//			Writing in assembly is too time consuming.
//NOTE:		When optimize == GLH_OPTIMIZE_MMX_SSE, alignment is not necessary.
GLint GLHLIB_API glhPerlinNoise2D(GLfloat *result, GLint interpolationQuality, GLint mode, GLint optimize, GLfloat *pos, GLfloat persistence, GLint numberOfOctaves, GLint *boolOctave);

//PURPOSE:	Generate a 3D noise function, based on persistence which
//			is defined as
//			frequency = 2^i
//			amplitude = persistence^i
//			in other words ...
//			ln(amplitude) = i*ln(persistence)
//			ln(amplitude)/ln(persistence) = i
//			frequency = 2^ln(amplitude)/ln(persistence)  <----
//
//			The numberOfOctaves which controls how many frequencies to sum up
//			boolOctave is an array the size of numberOfOctaves, with GL_TRUE and GL_FALSE
//			to control which ones to sum up.
//			interpolationQuality should be GLH_INTERPOLATIONQUALITY_LINEAR for low quality
//				GLH_INTERPOLATIONQUALITY_COS for high
//			mode can be GLH_MODE_STANDARD, GLH_MODE_ALTERNATE, GLH_MODE_ALTERNATE2, GLH_MODE_ALTERNATE3, GLH_MODE_ALTERNATE4
//
//			optimize can be GLH_OPTIMIZE_NONE
//
//			pos is 3 floats that describe a position in 3D
//
//			The result is a single float and is written to *result.
//
//			Returns 1 for sucess, -1 if bad parameter passed
GLint GLHLIB_API glhPerlinNoise3D(GLfloat *result, GLint interpolationQuality, GLint mode, GLint optimize, GLfloat *pos, GLfloat persistence, GLint numberOfOctaves, GLint *boolOctave);

/*Block 5 -end*/

/*Block 6 -start*/
/*Block 6 -end*/

/*Block 7 -start*/
/*Block 7 -end*/

/*Block 8 -start*/

//PURPOSE: Initialize OpenGL 1.1 hints.
void GLHLIB_API glhInitializeHints(GLenum mode);

/*Block 8 -end*/

/*Block 9 -start*/
//****************************************************************************
//SOFTWARE TRANSFORM OPERATIONS. DOES NOT USE OPENGL.
//Multiply matrix by vertex. Multiply vertex by matrix. Multiply matrix by matrix.

//PURPOSE:	Returns 1 fo success, 0 for error (division by w=0.0)
//			windowCoordinate is (x, y, z)
GLint GLHLIB_API glhProjectd(GLdouble objx, GLdouble objy, GLdouble objz,
				GLdouble *modelview, GLdouble *projection,
				GLint *viewport,
				GLdouble *windowCoordinate);
GLint GLHLIB_API glhProjectf(GLfloat objx, GLfloat objy, GLfloat objz,
				GLfloat *modelview, GLfloat *projection,
				GLint *viewport,
				GLfloat *windowCoordinate);

//PURPOSE:	Singular matrix or division by w=0.0 return 0, else 1 for success.
//			objectCoordinates is (x, y, z)
GLint GLHLIB_API glhUnProjectd(GLdouble winx, GLdouble winy, GLdouble winz,
				GLdouble *modelview, GLdouble *projection,
				GLint *viewport,
				GLdouble *objectCoordinates);
GLint GLHLIB_API glhUnProjectf(GLfloat winx, GLfloat winy, GLfloat winz,
				GLfloat *modelview, GLfloat *projection,
				GLint *viewport,
				GLfloat *objectCoordinates);

//PURPOSE:	Returns 0 fo success, >0 for number of errors (division by w=0.0)
//			Example: If you have 5 vertices to process, then totalVertex4D=4*5
//			NOTE: the w of windowCoordinate4D won't be written to.
//			NOTE: we assume w component of objectVertex4D contains any value.
GLint GLHLIB_API glhProjectf_2(GLint totalVertex4D, GLfloat *objectVertex4D,
				GLfloat *modelview_projection,
				GLint *viewport,
				GLfloat *windowCoordinate4D);
//			Example: If you have 5 vertices to process, then totalVertex4D=3*5
GLint GLHLIB_API glhProjectf_3(GLint totalVertex3D, GLfloat *objectVertex3D,
				GLfloat *modelview_projection,
				GLint *viewport,
				GLfloat *windowCoordinate3D);
//PURPOSE:	Returns 0 for success, >0 for singular matrix or division by w=0.0
//			NOTE: objectVertex4D will contain 1/w instead of 1.0
//			NOTE: we ignore w component of windowCoordinate4D
GLint GLHLIB_API glhUnProjectf_2(GLint totalVertex4D, GLfloat *windowCoordinate4D,
				GLfloat *inverse_modelview_projection,
				GLint *viewport,
				GLfloat *objectVertex4D);
GLint GLHLIB_API glhUnProjectf_3(GLint totalVertex3D, GLfloat *windowCoordinate3D,
				GLfloat *inverse_modelview_projection,
				GLint *viewport,
				GLfloat *objectVertex3D);
//PURPOSE:	Returns 0 fo success, >0 for number of errors (division by w=0.0)
//			Memory access must be 16 byte aligned (128 bit) so objectVertex,
//			modelview_projection, windowCoordinate should
//			be a valid address, EXCEPT viewport, which doesn't matter.
//			Vertices are (x, y, z, w) windowCoordinate are (x, y, z, w)
//			For windowCoordinate, the result is x and y are window coordinates,
//			z is window space z
//			NOTE: we ignore w component of windowCoordinate4D
//			Example: If you have 5 vertices to process, then totalVertex4D=4*5
GLint GLHLIB_API glhProjectf_SSE_Aligned_2(GLint totalVertex4D, GLfloat *objectVertex4D,
				 GLfloat *modelview_projection,
				 GLint *viewport,
				 GLfloat *windowCoordinate4D);
//			The following might give a boost in performance. Pentium 3, Pentium 4, Athlon XP
GLint GLHLIB_API glhProjectf_SSE_Aligned_WarmCache_2(GLint totalVertex4D, GLfloat *objectVertex4D,
				 GLfloat *modelview_projection,
				 GLint *viewport,
				 GLfloat *windowCoordinate4D);
//			Same as above, but we don't care about alignment (lower performance)
GLint GLHLIB_API glhProjectf_SSE_Unaligned_2(GLint totalVertex4D, GLfloat *objectVertex4D,
				 GLfloat *modelview_projection,
				 GLint *viewport,
				 GLfloat *windowCoordinate4D);
//PURPOSE:	Returns 0 for success, >0 for singular matrix or division by w=0.0
//			Look at comment for glhProjectf_SSE_Aligned_2
GLint GLHLIB_API glhUnProjectf_SSE_Aligned_2(GLint totalVertex4D, GLfloat *windowCoordinate4D,
				GLfloat *inverse_modelview_projection,
				GLint *viewport,
				GLfloat *objectVertex4D);
//			The following might give a boost in performance. Pentium 3, Pentium 4, Athlon XP
GLint GLHLIB_API glhUnProjectf_SSE_Aligned_WarmCache_2(GLint totalVertex4D, GLfloat *windowCoordinate4D,
				GLfloat *inverse_modelview_projection,
				GLint *viewport,
				GLfloat *objectVertex4D);
//			Same as above, but we don't care about alignment (lower performance)
GLint GLHLIB_API glhUnProjectf_SSE_Unaligned_2(GLint totalVertex4D, GLfloat *windowCoordinate4D,
				GLfloat *inverse_modelview_projection,
				GLint *viewport,
				GLfloat *objectVertex4D);

//PURPOSE:	Do a 4x4 matrix multiplication on vector
//			NOTE: Assuming w of vector4D is any value.
//			Example: if we have 5 vertices, totalVertex4D=4*5
//			Returns always 0.
GLint GLHLIB_API glhMultiplyMatrixByVector4by4f_1(GLint totalVector4D, GLfloat *vector4D,
				GLfloat *matrix,
				GLfloat *result4D);
//			This similarly does a matrix multiplication and ignores w of result3D.
//			w of vector3D is assumed to be 1.0
GLint GLHLIB_API glhMultiplyMatrixByVector4by4f_2(GLint totalVector3D, GLfloat *vector3D,
				GLfloat *matrix,
				GLfloat *result3D);
//			This similarly does a matrix multiplication and ignores w of result3D.
//			w of vector3D is assumed to be 0.0.
//			This is suitable for transforming normals.
GLint GLHLIB_API glhMultiplyMatrixByVector4by4f_3(GLint totalVector3D, GLfloat *vector3D,
				GLfloat *matrix,
				GLfloat *result3D);

//PURPOSE:	Do a vector multiplication on a 4x4 matrix (UNLIKE glhMultiplyMatrixByVector4by4f_1
//			which is matrix * vector
//
//			NOTE: Assuming w of vector4D is any value.
//			Example: if we have 5 vertices, totalVertex4D=4*5
//			Returns always 0.
GLint GLHLIB_API glhMultiplyVectorByMatrix4by4f_1(GLint totalVector4D, GLfloat *vector4D,
				GLfloat *matrix,
				GLfloat *result4D);
//			This similarly does a matrix multiplication and ignores w of result3D.
//			w of vector3D is assumed to be 1.0
GLint GLHLIB_API glhMultiplyVectorByMatrix4by4f_2(GLint totalVector3D, GLfloat *vector3D,
				GLfloat *matrix,
				GLfloat *result3D);
//			This similarly does a matrix multiplication and ignores w of result3D.
//			w of vector3D is assumed to be 0.0.
//			This is suitable for transforming normals.
GLint GLHLIB_API glhMultiplyVectorByMatrix4by4f_3(GLint totalVector3D, GLfloat *vector3D,
				GLfloat *matrix,
				GLfloat *result3D);

//PURPOSE:	Do a 4x4 matrix multiplication on vector using SSE
//			All data must be 16 byte aligned.
//			It avoids cache pollution and reduces unecessary bus traffic.
//			NOTE: Assuming w of vector4D is any value.
//			Example: if we have 5 vertices, totalVertex4D=4*5
GLint GLHLIB_API glhMultiplyMatrixByVector4by4f_SSE_Aligned_1(GLint totalVector4D, GLfloat *vector4D,
				GLfloat *matrix,
				GLfloat *result4D);
//			The following might give a boost in performance. Pentium 3, Pentium 4, Athlon XP
//			This version warms the cache to reduce latency.
//			It avoids cache pollution and reduces unecessary bus traffic.
GLint GLHLIB_API glhMultiplyMatrixByVector4by4f_SSE_Aligned_WarmCache_1(GLint totalVector4D, GLfloat *vector4D,
				GLfloat *matrix,
				GLfloat *result4D);

//PURPOSE:	Multiply leftMatrix[16] with rightMatrix[16] and write result to result[16]
//			It does this only once. See glhMultiplyMatrixByMatrix4by4f_2.
void GLHLIB_API glhMultiplyMatrixByMatrix4by4f_1(GLfloat *leftMatrix, GLfloat *rightMatrix, GLfloat *result);
//PURPOSE:	Multiply leftMatrix[16] with rightMatrix[16] and write result to result[16]
//			It does this countMatrix number of times.
//			For example, for 2 matrix mult, countMatrix must be 2.
void GLHLIB_API glhMultiplyMatrixByMatrix4by4f_2(GLint countMatrix, GLfloat *leftMatrix, GLfloat *rightMatrix, GLfloat *result);

//PURPOSE:	**** SSE version of glhMultiplyMatrixByMatrix4by4f_1
//			Multiply leftMatrix[16] with rightMatrix[16] and write result to result[16]
//			It does this only once. See glhMultiplyMatrixByMatrix4by4f_2.
void GLHLIB_API glhMultiplyMatrixByMatrix4by4f_SSE_Aligned_WarmCache_1(GLfloat *leftMatrix, GLfloat *rightMatrix, GLfloat *result);

//PURPOSE:	**** 3DNow! version of glhMultiplyMatrixByMatrix4by4f_1
//			Multiply leftMatrix[16] with rightMatrix[16] and write result to result[16]
//			It does this only once. See glhMultiplyMatrixByMatrix4by4f_2.
void GLHLIB_API glhMultiplyMatrixByMatrix4by4f_3DNow(GLfloat *leftMatrix, GLfloat *rightMatrix, GLfloat *result);

//PURPOSE:	**** 3DNow! version of glhMultiplyMatrixByMatrix4by4f_1
//			Multiply leftMatrix[16] with rightMatrix[16] and write result to result[16]
//			It does this only once. See glhMultiplyMatrixByMatrix4by4f_2.
void GLHLIB_API glhMultiplyMatrixByMatrix4by4f_3DNow_1(GLfloat *leftMatrix, GLfloat *rightMatrix, GLfloat *result);

/*Block 9 -end*/

/*Block 10 -start*/
//**************************************************************************************************
//MISCELLANEOUS MATRIX OPERATIONS. DOES NOT USE OPENGL.
//ANGLES ARE IN RADIANS WITH SOME EXCEPTIONS.

//PURPOSE:	After calling
//			GLfloat matrix[16], eyePosition3D[3], center3D[3], upVector3D[3];
//			glhLoadIdentityf2(matrix);
//			glhLookAtf2(matrix, eyePosition3D, center3D, upVector3D);
//
//			you might want to retreive eyePosition3D, center3D and upVector3D directly from the matrix.
//			This function will attempt to do so.
//			**** WARNING : center3D will not be the original value you input because this information is lossed when
//			               you call glhLookAtf2
//			               center3D will be eyePosition3D + normalize(lookAtVector)
//
//			Hopefully, the matrix contains valid data else extracting will be a problem.
//			Even if you call glhRotatef2, glhTranslatef2 and other functions, this function will be able to extract
//			the new glhLookAt2 variables.
//
//PARAMETERS:
//			[in] matrix : Column major 4x4 matrix
//			[out] eyePosition3D : Position of the "eye" aka camera position
//			[out] center3D : The point at which we are looking at
//			[out] upVector3D : A normalized up vector
//
//RETURN:
//			1 for success (Most likely)
//			-1 for error. (Most likely the matrix contains some unexpected entries in the upper left 3x3 matrix.)
GLint GLHLIB_API glhExtractLookAtFromMatrixd2(GLdouble *matrix, GLdouble *eyePosition3D, GLdouble *center3D, GLdouble *upVector3D);
GLint GLHLIB_API glhExtractLookAtFromMatrixf2(GLfloat *matrix, GLfloat *eyePosition3D, GLfloat *center3D, GLfloat *upVector3D);

//PURPOSE:	Give a 4x4 matrix in OpenGL format, returns TRUE or FALSE
//			For double, the result must be accurate to 1.0e-12
//			For float, the result must be accurate to 1.0e-6
GLint GLHLIB_API glhIsMatrixRotationMatrixd(GLdouble *matrix);
GLint GLHLIB_API glhIsMatrixRotationMatrixf(GLfloat *matrix);
void GLHLIB_API glhExtractAnglesFromRotationMatrixd2(GLdouble *matrix, GLdouble *xAngleRadians, GLdouble *yAngleRadians, GLdouble *zAngleRadians);
void GLHLIB_API glhExtractAnglesFromRotationMatrixf2(GLfloat *matrix, GLfloat *xAngleRadians, GLfloat *yAngleRadians, GLfloat *zAngleRadians);

/*Block 10 -end*/

/*Block 11 -start*/

//PURPOSE:	Used in OpenGL, for making image dimension power of 2 by undercompensating.
//			if((width==*widthOpenGL)&&(height==*heightOpenGL)) return 1 else return 0.
GLint GLHLIB_API glhLowerPowerOfTwo(GLint width, GLint *widthOpenGL, GLint height, GLint *heightOpenGL);

//PURPOSE:	Used in OpenGL, for making image dimension power of 2 by overcompensating.
//			if((width==*widthOpenGL)&&(height==*heightOpenGL)) return 1 else return 0.
GLint GLHLIB_API glhHigherPowerOfTwo(GLint width, GLint *widthOpenGL, GLint height, GLint *heightOpenGL);

//PURPOSE:	Used in OpenGL, for making image dimension power of 2 by undercompensating.
//			if(value==*newValue) return 1 else return 0
GLint GLHLIB_API glhLowerPowerOfTwo2(GLint value, GLint *newValue);

//PURPOSE:	Used in OpenGL, for making image dimension power of 2 by overcompensating.
//			if(value==*newValue) return 1 else return 0
GLint GLHLIB_API glhHigherPowerOfTwo2(GLint value, GLint *newValue);

/*Block 11 -end*/

/*Block 12 -start*/
//**************************************************************************************************
//SOFTWARE MATRIX OPERATIONS. DOES NOT USE OPENGL.
//ANGLES ARE IN RADIANS WITH SOME EXCEPTIONS.

//PURPOSE:	For software transformation, so that a call to glGetFloatv() or glGetDoublev()
//			can be avoided. SSE and 3D Now! versions may be produced later on.
void GLHLIB_API glhLoadIdentityd2(GLdouble *matrix);
void GLHLIB_API glhLoadIdentityf2(GLfloat *matrix);
void GLHLIB_API glhTranslated2(GLdouble *matrix, GLdouble x, GLdouble y, GLdouble z);
void GLHLIB_API glhTranslatef2(GLfloat *matrix, GLfloat x, GLfloat y, GLfloat z);
void GLHLIB_API glhScaled2(GLdouble *matrix, GLdouble x, GLdouble y, GLdouble z);
void GLHLIB_API glhScalef2(GLfloat *matrix, GLfloat x, GLfloat y, GLfloat z);
void GLHLIB_API glhRotated2(GLdouble *matrix, GLdouble angleInRadians, GLdouble x, GLdouble y, GLdouble z);
void GLHLIB_API glhRotatef2(GLfloat *matrix, GLfloat angleInRadians, GLfloat x, GLfloat y, GLfloat z);
void GLHLIB_API glhRotateAboutXd2(GLdouble *matrix, GLdouble angleInRadians);
void GLHLIB_API glhRotateAboutXf2(GLfloat *matrix, GLfloat angleInRadians);
void GLHLIB_API glhRotateAboutYd2(GLdouble *matrix, GLdouble angleInRadians);
void GLHLIB_API glhRotateAboutYf2(GLfloat *matrix, GLfloat angleInRadians);
void GLHLIB_API glhRotateAboutZd2(GLdouble *matrix, GLdouble angleInRadians);
void GLHLIB_API glhRotateAboutZf2(GLfloat *matrix, GLfloat angleInRadians);
void GLHLIB_API glhPerspectived2(GLdouble *matrix, GLdouble fovyInDegrees, GLdouble aspectRatio, GLdouble znear, GLdouble zfar);
void GLHLIB_API glhPerspectivef2(GLfloat *matrix, GLfloat fovyInDegrees, GLfloat aspectRatio, GLfloat znear, GLfloat zfar);
void GLHLIB_API glhFrustumd2(GLdouble *matrix, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble znear, GLdouble zfar);
void GLHLIB_API glhFrustumf2(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar);
void GLHLIB_API glhOrthod2(GLdouble *matrix, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble znear, GLdouble zfar);
void GLHLIB_API glhOrthof2(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar);
void GLHLIB_API glhMergedFrustumd2(GLdouble *matrix, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble znear, GLdouble zfar);
void GLHLIB_API glhMergedFrustumf2(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear, GLfloat zfar);
void GLHLIB_API glhMergedPerspectived2(GLdouble *matrix, GLdouble fovyInDegrees, GLdouble aspectRatio, GLdouble znear, GLdouble zfar);
void GLHLIB_API glhMergedPerspectivef2(GLfloat *matrix, GLfloat fovyInDegrees, GLfloat aspectRatio, GLfloat znear, GLfloat zfar);
void GLHLIB_API glhFrustumInfiniteFarPlaned2(GLdouble *matrix, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble znear);
void GLHLIB_API glhFrustumInfiniteFarPlanef2(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat znear);
void GLHLIB_API glhPerspectiveInfiniteFarPlaned2(GLdouble *matrix, GLdouble fovyInDegrees, GLdouble aspecRatio, GLdouble znear);
void GLHLIB_API glhPerspectiveInfiniteFarPlanef2(GLfloat *matrix, GLfloat fovyInDegrees, GLfloat aspectRatio, GLfloat znear);
void GLHLIB_API glhLookAtd2(GLdouble *matrix, GLdouble *eyePosition3D, GLdouble *center3D, GLdouble *upVector3D);
void GLHLIB_API glhLookAtf2(GLfloat *matrix, GLfloat *eyePosition3D, GLfloat *center3D, GLfloat *upVector3D);
void GLHLIB_API glhMultMatrixd2(GLdouble *result_leftMatrix, GLdouble *rightMatrix);
void GLHLIB_API glhMultMatrixf2(GLfloat *result_leftMatrix, GLfloat *rightMatrix);
void GLHLIB_API glhMultMatrixSwappedd2(GLdouble *result_rightMatrix, GLdouble *leftMatrix);
void GLHLIB_API glhMultMatrixSwappedf2(GLfloat *result_rightMatrix, GLfloat *leftMatrix);

//SSE versions of the above. Does the matrix multiplication with SSE
//Column major matrix goes wells with SSE.
//Cache warming is used where appropriate for more performance.
//**** A call to glhInitLibrary() is required. Don't forget to call glhShutDownLibrary() when shutting down.
//**** Because need to allocate some RAM and then deallocate
//xyzw in which w = 1.0
//Make sure all pointer to array is aligned 16 byte else you will get crash.
//Will not implement unaligned version.
void GLHLIB_API glhTranslatef2_SSE_Aligned(GLfloat *matrix, GLfloat *xyzw);
void GLHLIB_API glhScalef2_SSE_Aligned(GLfloat *matrix, GLfloat *xyzw);
void GLHLIB_API glhRotatef2_SSE_Aligned(GLfloat *matrix, GLfloat angleInRadians, GLfloat *xyzw);
//These don't give any benifits
//void GLHLIB_API glhRotateAboutXf2_SSE_Aligned(GLfloat *matrix, GLfloat angleInRadians);
//void GLHLIB_API glhRotateAboutYf2_SSE_Aligned(GLfloat *matrix, GLfloat angleInRadians);
//void GLHLIB_API glhRotateAboutZf2_SSE_Aligned(GLfloat *matrix, GLfloat angleInRadians);

//Most of the other ones aren't called so often so why bother optimizing. (Ex : glhPerspectivef2)

//Likely to get called often
void GLHLIB_API glhMultMatrixf2_SSE_Aligned(GLfloat *result_leftMatrix, GLfloat *rightMatrix);
void GLHLIB_API glhMultMatrixSwappedf2_SSE_Aligned(GLfloat *result_rightMatrix, GLfloat *leftMatrix);


//PURPOSE:	A fast way to get the inverse, compared to glhInvertMatrixdv_2 and glhInvertMatrixfv_2
//			matrix should not have any scale factor and matrix should be an orthogonal
//			matrix, and typically these are true for 3D graphics.
void GLHLIB_API glhQuickInvertMatrixd2(GLdouble *m, GLdouble *result);
void GLHLIB_API glhQuickInvertMatrixf2(GLfloat *m, GLfloat *result);

void GLHLIB_API glhTransposeMatrixd2(GLdouble *result, GLdouble *m);
void GLHLIB_API glhTransposeMatrixf2(GLfloat *result, GLfloat *m);

//PURPOSE:	Singular matrix return 0, else 1 for success.
GLint GLHLIB_API glhInvertMatrixd2(GLdouble *m, GLdouble *result);
GLint GLHLIB_API glhInvertMatrixf2(GLfloat *m, GLfloat *result);

//PURPOSE:	Constructs a shadow matrix. When this matrix is applied to the current GL
//			matrix (probably modelview), all vertices are mapped to a plane with equation
//			A*x + B*y + C*z + D = 0
//			All that is needed is the plane equation for the ground or what else have you,
//			and the light position.
//			planeEquation is the A B C D of the plane.
//			lightPosition is xyzw.
//HOW TO USE:	Apply this matrix after the camera matrix and before the world matrix.
//				The world matrix is for transforming the object to the "world". GL does not
//				have the notion of camera and world matrices but that's another issue.
//
//				glLoadMatrixf(CameraMatrix);
//				glhShadowMatrixf(planeEquation, lightPosition);
//				glMultMatrixf(WorldMatrix);
//
//				You may want to color the shadows as some dark color and perhaps use the stencil
//				to avoid double (or more) shadowing.
void GLHLIB_API glhShadowMatrixd2(GLdouble *matrix, GLdouble *planeEquation, GLdouble *lightPosition);
void GLHLIB_API glhShadowMatrixf2(GLfloat *matrix, GLfloat *planeEquation, GLfloat *lightPosition);

//PURPOSE:	In some software, some elements in the 3D scene (with perspective view of course)
//			certain object preserve their scale no matter from where you look at them.
//			glhConstantSizeMatrix will build a modelview matrix that does just that.
//			Why doesn't this function apply the matrix transform onto the GL matrix stack?
//			Keep in mind that this is a "2" function. It doesn't use or touch GL at all.
//			Also, see glhConstantSizeMatrixf, glhConstantSizeMatrixd
//HOW TO USE:	GLfloat newModelview[16];		//Column major matrix, 4x4
//				GLfloat objectCenter[4];		//Compute this yourself (XYZW where W = 1.0)
//				GLfloat modelview_projection[16];	//This is P * M
//				GLfloat modelview[16];			//The previous matrix on the stack.

//				glPushMatrix();		//Push old modelview matrix to preserve it
//				glhConstantSizeMatrixf2(newModelview, objectCenter, modelview_projection, modelview, viewport);
//				glLoadMatrixf(newModelview);
//				DrawMyObject();
//				glPopMatrix();
void GLHLIB_API glhConstantSizeMatrixf2(GLfloat *newModelview, GLfloat *objectCenter, GLfloat *modelview_projection, GLfloat *modelview, GLint *viewport);

//PURPOSE:	For creating a matrix for generalized planar reflection.
//			Typically, people reflect about the xz-plane or xy-plane or yz-plane using glScale(1.0, -1.0, 1.0)
//			or glScale(1.0, 1.0, -1.0) or glScale(-1.0, 1.0, 1.0) and then setup the stencil bits and render
//			everything with polygon orientation reversed (glFrontFace).
//			With this function, you can set an arbitrary reflection plane. Load into into the modelview matrix
//			and reverse polygon orientation, then render everything.
//			Be sure to reflect lights as well (glLightf).
//
//PARAMETERS:
//			[out] matrix : is an array of 16 floats (GL column matrix) and should contain identity matrix
//			               or previous transform. The resulting matrix will be stored here.
//			[in] ptransformArray : is an array of floats that contains (centerx of mirror, centery of mirror, centerz of
//			                       mirror, self-rotation about x, self-rotation about y, self-rotation about z).
//			                       Self rotation means rotating an object about its center point.
//			                       The rotation is for the mirror.
//			                       ***** The rotations must be in RADIANS as usual*****
//
//HOW TO USE:
//We assume the mirror is positioned in the world like this
//If your transform sequence is different than this, it won't work for you :
//glTranslatef(mirrorX, mirrorY, mirrorZ);
//glRotatef(mirror_Z_rotation, 0.0, 0.0, 1.0);
//glRotatef(mirror_Y_rotation, 0.0, 1.0, 0.0);
//glRotatef(mirror_X_rotation, 1.0, 0.0, 0.0);
//
//where mirror vertices are (positioned on the xy plane at z=0.0)
//{-1.0, -1.0, 0.0} {1.0, -1.0, 0.0} {-1.0, 1.0, 0.0} {1.0, 1.0, 0.0}
//
//When you call glhGeneralPlanarMirrorf_1 to generate the matrix, before you render the geometry of your stuff to be mirrored,
//call glMultMatrixf to upload (and multiply) to GL.
void GLHLIB_API glhGeneralPlanarMirrorf_1(GLfloat *matrix, GLfloat *ptransformArray);

//PURPOSE:	Same as glhGeneralPlanarMirrorf_1, but ptransformArray is split into ptranslate[3] and pselfRotate[3]
void GLHLIB_API glhGeneralPlanarMirrorf_2(GLfloat *matrix, GLfloat *ptranslate, GLfloat *pselfRotate);

//PURPOSE:	Assume you have an object that has already a rotation matrix applied to it. Call
//			the rotation R1. Let's say you want to apply another rotation to the object. Call it R2
//			but you no longer want to apply R1. The solution is to find the inverse of R1 and then
//			apply R2.
//			This functions will use glhQuickInvertMatrixf2 and then glhMultMatrixf2
void GLHLIB_API glhRotationMatrixFromRotationsf2(GLfloat *result_Matrix, GLfloat *R1, GLfloat *R2);

/*Block 12 -end*/

/*Block 13 -start*/
/*Block 13 -end*/

/*Block 14 -start*/
//**************************************************************************************************
//GLH ERROR DETECTION

//PURPOSE:	Get error code as GLint. See Block 0 for the #defines.
//			Once all errors are picked up by calling glhGetError, further calls will return GLH_ERROR_NONE.
//			The error stack is 100 elements deep.
//			Be sure to call glhInitLibrary and glhShutDownLibrary.
GLint GLHLIB_API glhGetError();

//PURPOSE:	Get the glh error and copy it into the pstring.
//			Returns 1 if pstring==NULL
//			Returns 1 if no errors found, else it returns -1.
GLint GLHLIB_API glhCopyErrorInto_cBuffer(char *pstring);
/*Block 14 -end*/

/*Block 15 -start*/
//**************************************************************************************************
//SOME NORMAL MAP AND HEIGHT MAP PROCESSING FUNCTIONS

//PURPOSE:	Using a height map, create a normal map.
//			The height map can be grayscale (8 bit), RGB8 (24 bit) or RGBA (32 bit)
//
//PARAMETERS:
//			[in] dataAlignment : must be 1 or 4.
//			[in] width and height : must be 2^n + 2*(border) where border is 0 or 1.
//			[in] border : 0 or 1
//			[in] scaleFactor : You should choose a good scale factor (4.0)
//			[in] isPromoteToHigherPowerOn : is ignored for now
//			[in] format : is for indata.
//			              It can be GL_LUMINANCE
//			              It can be GL_RGB (we will use red for height)
//			              It can be GL_BGR (we will use blue for height)
//			              It can be GL_RGBA (we will use red for height)
//			              It can be GL_BGRA (we will use blue for height)
//			              It can be GL_ABGR (we will use alpha for height)
//			[in] indata : Pointer to array of pixels
//			[in] outformat : must be GL_RGBA, GL_BGRA or GL_ABGR (always 32 bpp!)
//			                 Alpha of output will be maximum, in this case 255.
//			[out] outdata : must be previously allocated, of width x height x 4 with 0 border.
//
//RETURN:
//			1 for success
//			-1 on failure
//
//UPDATE:	Updated to work with glhGetError. If GLint returns error, call glhGetError.
GLint GLHLIB_API glhConvertHeightMapToNormalMap(GLint dataAlignment, GLint width, GLint height, GLint border, GLfloat scaleFactor,
								GLboolean isPromoteToHigherPowerOn, GLenum format, const GLubyte *indata, GLenum outformat, GLubyte *outdata);


//PURPOSE:	Given a normal map, LERP normal with its neightbor :
//			new_normal = normal = (1-weightFactor) * neighbor_normal + weightFactor * normal
//
//			The effect is that it reduces the difference between neighboring normals.
//			If a rightmost pixel is reached, it's right neighbor is in column 0.
//			If a leftmost pixel is reached, it's left neightbor is the last column.
//			If a topmost pixel is reached, it's neighbor is on the bottom row of pixels.
//			If a bottommost pixel is reached, it's neighbor is on the top row of pixels.
//			Basically, this is a wraparound operation.
//
//PARAMETERS:
//			[in] dataAlignment : must be 1 or 4.
//			[in] width and height : must be 2^n + 2*(border) where border is 0 or 1.
//			[in] border : 0 or 1
//			[in] weightFactor : You should choose a value from 0.0 to 1.0. The code will not check if this is out of range.
//			[in] format : is for indata and outdata
//			              It can be GL_RGBA (we will use red for height)
//			              It can be GL_BGRA (we will use blue for height)
//			              It can be GL_ABGR (we will use alpha for height)
//			[in] indata : Pointer to array of pixels
//			[out] outdata : must be previously allocated, of width x height x 4 with 0 border.
//			[in] param : Use GLH_UP, GLH_DOWN, GLH_LEFT, GLH_RIGHT. You can OR them together.
//			             Example, if you specify GLH_UP, the neighbor pixel would be the pixel right above the current pixel.
//			             The only valid value is GLH_UP | GLH_DOWN | GLH_LEFT | GLH_RIGHT
//
//RETURN:
//			1 for success
//			-1 on failure
//
//UPDATE:	Updated to work with glhGetError. If GLint returns error, call glhGetError.
GLint GLHLIB_API glhNormalMapReducer(GLint dataAlignment, GLint width, GLint height, GLint border, GLfloat weightFactor, GLenum format, const GLubyte *indata, GLubyte *outdata, GLint param);

/*Block 15 -end*/


/*Block 16 -start*/
//**************************************************************************************************
//NORMAL VECTOR, TANGENT VECTOR, BINORMAL VECTOR

//PURPOSE:	Compute tangent and binormal vectors.
//			index, vertex, normal and tex coords must be supplied and
//			memory for tangent and binormal vectors should be allocated externally.
//			**** There are 2 functions : One for GLuint indices (32 bit), one for GLushort indices (16 bit)
//
//PARAMETERS:
//			[in] totalIndices : The number of indices in pindices
//			[in] pindices : Array containing the indices
//			[in] totalVertex : The number of vertices
//			[in] numCompVertex : is the number of components per vertex. 3 or 4.
//			[in] pvertex : Array containing the vertices
//			[in] numCompNormals : is the number of components per normal. 3 or 4.
//			[in] pnormals : Array containing the normals
//			[in] numCompTexCoord : is the number of components per texcoord. 2 or 3 or 4.
//			[in] ptexCoord : Array containing the texcoords
//			[in] numCompTangent : is the number of components per tangent. 3 or 4.
//			[out] ptangent : Array containing the tangents
//			[in] numCompBinormal : is the number of components per binormals. 3 or 4.
//			[out] pbinormal : Array containing the binormals
//
//RETURN:
//			1 for success
//			-1 if bad values passed (0 for array size, components have an invalid value), GLH_ERROR_INVALID_PARAM
//			0 for memory error, GLH_ERROR_OUT_OF_MEMORY
//UPDATE:	Updated to work with glhGetError. If GLint returns error, call glhGetError.
GLint GLHLIB_API glhComputeTangentAndBinormalVectors_v1_f(GLint totalIndices, GLuint *pindices, GLint totalVertex, GLint numCompVertex, GLfloat *pvertex, GLint numCompNormals, GLfloat *pnormals, GLint numCompTexCoord, GLfloat *ptexCoord, GLint numCompTangent, GLfloat *ptangent, GLint numCompBinormal, GLfloat *pbinormal);
GLint GLHLIB_API glhComputeTangentAndBinormalVectors_v1_f_2(GLint totalIndices, GLushort *pindices, GLint totalVertex, GLint numCompVertex, GLfloat *pvertex, GLint numCompNormals, GLfloat *pnormals, GLint numCompTexCoord, GLfloat *ptexCoord, GLint numCompTangent, GLfloat *ptangent, GLint numCompBinormal, GLfloat *pbinormal);


/*Block 16 -end*/

/*Block 17 -start*/
/*Block 17 -end*/

/*Block 18 -start*/
//REFLECTION / REFRACTION

//PURPOSE: reflect = 2 * dot(N, I) * N - I
//       <  ^  >
//        \ | /
//         \|/  the left one is I (incident), the center one is N (normal), the right is reflected
//=====================
//N and I should be normalized.
//
//reflected is pointer to a sequence of 3D vectors
//pincidentVector is pointer to a sequence of 3D vectors
//pnormal is pointer to a sequence of 3D vectors
//count is number of vectors to be processed
void GLHLIB_API glhComputeReflectedVectorf(GLfloat *reflected, GLfloat *pincidentVector, GLfloat *pnormal, GLint count);

//PURPOSE:
//       <  ^   
//        \ |  
//         \|   the left one is I (incident), the center one is N (normal), the right is refracted
//			\
//			 \
//			  >
//=====================
//N and I should be normalized.
//eta is the ratio of the indices (from material / to be entered material)
//
//refracted is pointer to a sequence of 3D vectors
//pincidentVector is pointer to a sequence of 3D vectors
//pnormal is pointer to a sequence of 3D vectors
//eta is constant for the material and the wavelength
//count is number of vectors to be processed
//
//NOTE:	It might be a good idea to take total internal reflection into account
//		using external code.
void GLHLIB_API glhComputeRefractedVectorf(GLfloat *refracted, GLfloat *pincidentVector, GLfloat *pnormal, GLfloat eta, GLint count);

/*Block 18 -end*/

/*Block 19 -start*/
//****************************************************************************
//QUATERNION RELATED

//PURPOSE:	Set quat to {0, 0, 0, 1}
void GLHLIB_API glhQuaternionIdentityf(GLfloat *quat);

//PURPOSE:	If quat is {0, 0, 0, 1}, returns 1 (GL_TRUE), else 0 (GL_FALSE)
GLint GLHLIB_API glhQuaternionIsIdentityf(GLfloat *quat);

//PURPOSE:	If quat[3] == 1.0, returns 1 (GL_TRUE), else 0 (GL_FALSE)
GLint GLHLIB_API glhQuaternionIsPuref(GLfloat *quat);

//PURPOSE:	Calculate the conjugate of a quat.
//			xyz is simply negated. quat is xyzw
void GLHLIB_API glhQuaternionConjugatef(GLfloat *quat);

//PURPOSE:	Calculate the magnitude of a quat.
void GLHLIB_API glhQuaternionMagnitudef(GLfloat *magnitude, GLfloat *quat);

//PURPOSE:	Calculate the magnitude squared of a quat.
void GLHLIB_API glhQuaternionMagnitudeSquaredf(GLfloat *magnitude, GLfloat *quat);

//PURPOSE:	Compute dot product between 2 quats.
void GLHLIB_API glhQuaternionDotProductf(GLfloat *result, GLfloat *quat1, GLfloat *quat2);

//PURPOSE:	Calculates the exponential of a quat.
//			quat is expected to be a pure quaternion. See glhQuaternionIsPuref.
void GLHLIB_API glhQuaternionExpf(GLfloat *outquat, GLfloat *quat);

//PURPOSE:	Calculate the natural logarithm of a quat.
//			quat should be unit quat.
void GLHLIB_API glhQuaternionLnf(GLfloat *outquat, GLfloat *quat);

//PURPOSE:	Normalize quat. Some glhQuaternion***** require normalized quats for efficiency.
//			GLfloat n=1.0/sqrtf(quat[0]*quat[0]+quat[1]*quat[1]+quat[2]*quat[2]+quat[3]*quat[3]);
//			quat[0]*=n;
//			quat[1]*=n;
//			quat[2]*=n;
//			quat[3]*=n;
void GLHLIB_API glhQuaternionNormalizef(GLfloat *quat);

//PURPOSE:	outquat = quat1 * quat2
//			If quat1 and quat2 are normalized, outquat will be a unit quat.
void GLHLIB_API glhQuaternionMultiplyf(GLfloat *outquat, GLfloat *quat1, GLfloat *quat2);

//PURPOSE:	Build a 4x4 column major rotation matrix from a quat.
//			quat should be normalized. See glhQuaternionNormalizef.
//
//		    |       2     2                                   |
//		    | 1 - 2Y  - 2Z    2XY - 2ZW      2XZ + 2YW      0 |
//		    |                                                 |
//		    |                       2     2                   |
//		M = | 2XY + 2ZW       1 - 2X  - 2Z   2YZ - 2XW      0 |
//		    |                                                 |
//		    |                                      2     2    |
//		    | 2XZ - 2YW       2YZ + 2XW      1 - 2X  - 2Y   0 |
//		    |                                                 |
//		    |     0               0              0          1 |
//
void GLHLIB_API glhQuaternionQuatToRotationMatrixf(GLfloat *matrix, GLfloat *quat);

//Same as glhQuaternionQuatToRotationMatrixf except this matrix is transposed.
//You might need to submit this version to GL.
void GLHLIB_API glhQuaternionQuatToRotationMatrixTf(GLfloat *matrix, GLfloat *quat);

//PURPOSE:	Build a quat from a 4x4 column major rotation matrix.
//			quat will be automatically normalized.
void GLHLIB_API glhQuaternionRotationMatrixToQuatf(GLfloat *quat, GLfloat *matrix);

//PURPOSE:	Convert quat to a axis of rotation and an angle in radians.
//			axis will receive xyz.
//			Quat should be normalized.
void GLHLIB_API glhQuaternionQuatToAxisAndAnglef(GLfloat *axis, GLfloat *angleInRadians, GLfloat *quat);

//PURPOSE:	Convert axis of rotation and an angle in radians to quat.
//			axis must be xyz. Should be unit vector.
void GLHLIB_API glhQuaternionAxisAndAngleToQuatf(GLfloat *quat, GLfloat *axis, GLfloat *angleInRadians);

//PURPOSE:	Convert Euler angles into a quat. Angles are in radians.
void GLHLIB_API glhQuaternionEulerAnglesToQuatf(GLfloat *quat, GLfloat roll, GLfloat pitch, GLfloat yaw);

//PURPOSE:	Interpolates between two quaternions, using spherical linear interpolation.
//			SLERP = Spherical Linear intERPolation
//			Interpolate 2 quats along smallest arc between them.
//			t is the interpolation factor where t = 0.0 gives outquat = quat1
//			and t = 1.0 gives outquat = quat2
//			t should be [0, 1]
//			You should make sure quat1 and quat2 are normalized.
void GLHLIB_API glhQuaternionSLERPf(GLfloat *outquat, GLfloat *quat1, GLfloat *quat2, GLfloat t);


/*Block 19 -end*/

/*Block 20 -start*/
//****************************************************************************
//FLOATING POINT NUMBER MANIPULATION

//PURPOSE:	Pack a 32 bit IEEE float into a array of 4 ubytes.
//			This works for numbers 0.0 to <1.0
//			Passing 1.0 gives 0.0
//			All numbers above and below this range are wrapped around.
//			This algorithm can be used in shaders where packing/unpacking may not be available.
//
//			The algorithm is :
//			GLfloat packFactors[] = { 1.0, 255.0, 65535.0, 16777215.0 };	//Better than { 1.0, 256.0, 65536.0, 16777216.0 }?
//			GLfloat Float[4];
//			Float[1]=Float[2]=Float[3]=Float[0]=inputNumber;	//Store copies
//			//MUL	float, float, packFactors;
//			Float[0]=Float[0]*packFactors[0];
//			Float[1]=Float[1]*packFactors[1];
//			Float[2]=Float[2]*packFactors[2];
//			Float[3]=Float[3]*packFactors[3];
//			//FRC	ub, Float;
//			outputNumber[0]=Float[0]-floor(Float[0]);
//			outputNumber[1]=Float[1]-floor(Float[1]);
//			outputNumber[2]=Float[2]-floor(Float[2]);
//			outputNumber[3]=Float[3]-floor(Float[3]);
void GLHLIB_API glhPackFloatIntoUByte(GLubyte *outputNumber, GLfloat inputNumber);

//PURPOSE:	Unpack a 32 bit IEEE float from an array of 3 ubytes to a single GLfloat.
//			This works for numbers 0.0 to <1.0
//			Passing 1.0 gives 0.0
//			All numbers above and below this range are wrapped around.
//			This algorithm can be used in shaders where packing/unpacking may not be available.
//
//			The algorithm is :
//			GLfloat extract[] = {1.0, 1.0/255.0, 1.0/65535.0, 1.0/16777215.0};	//Better than {1.0, 1.0/256.0, 1.0/65536.0, 1.0/16777216.0}?
//			//DP4	float, ub, extract;
//			*outputNumber=ub[0]*extract[0]+ub[1]*extract[1]+ub[2]*extract[2]+ub[3]*extract[3];
void GLHLIB_API glhUnpackUByteIntoFloat(GLfloat *outputNumber, const GLubyte *inputNumber);


//PURPOSE:	Given a 32 bit float, convert to 16 bit float.
//			Useful when you want to work with floats on the CPU, and then convert to 16 bit and send your
//			texture to OpenGL.
//			Or perhaps upload as a uniform for your shader.
void GLHLIB_API glhFloatToHalf(GLfloat infloat, GLushort &outhalf);

/*Block 20 -end*/

/*Block 21 -start*/
//****************************************************************************
//GEOMETRY GENERATION

//PURPOSE:	A common object from which specialized structs are derived
//			The previous glhCommonObject has been deleted and we now have glhCommonObject2
//			**** The same applies to the derived stuff ****
class glhCommonObject2
{
public:
	GLboolean		AverageNormals;							//Used in some cases

	GLint			TexCoordStyle[8];						//Used in some cases

	GLH_INDEXFORMAT	IndexFormat;
	GLint			TotalIndex;
	GLushort		*pIndex16Bit;							//Depends on IndexPrecision, one or the other will be used
	GLuint			*pIndex32Bit;							//Depends on IndexPrecision, one or the other will be used

	GLHVERTEXFORMAT	VertexFormat;							//One of the defines, see top of this file
	GLint			VertexCount;
	GLfloat			*pVertex;								//This receives the array of vertices
															//
};

//PURPOSE:	For use with function glhCreateCubef2 and glhDeleteCubef2
class glhCubeObject2 : public glhCommonObject2
{
public:
	GLfloat			Width, Height, Length;
	GLint			WidthDivision, HeightDivision, LengthDivision;
	
	GLuint			Start_DrawRangeElements;				//Parameter to pass to glDrawRangeElements
	GLuint			End_DrawRangeElements;					//Parameter to pass to glDrawRangeElements
};

//PURPOSE:	For use with function glhCylinderf2
class glhCylinderObject2 : public glhCommonObject2
{
public:
	GLboolean	IsThereATop, IsThereABottom;						//Render or not? If GL_FALSE, then it won't be computed and don't attempt to render.
	GLfloat		RadiusA, RadiusB, Height;							//RadiusA is top radius (+z), RadiusB is bottom radius (-z)
	
	GLint	Stacks;													//Number of divisions in the Theta direction
	GLint	Slices;													//Number of divisions in the Phi direction

	
	GLfloat			ScaleFactorS[8], ScaleFactorT[8];				//For texcoord

	//These 2 are for rendering the entire cylinder in one call to glDrawRangeElements
	GLuint			Start_DrawRangeElements;				//Parameter to pass to glDrawRangeElements
	GLuint			End_DrawRangeElements;					//Parameter to pass to glDrawRangeElements


	GLuint	Start_DrawRangeElements_BodyOfCylinder;					//Parameter to pass to glDrawRangeElements
	GLuint	End_DrawRangeElements_BodyOfCylinder;					//Parameter to pass to glDrawRangeElements
	GLuint	Start_DrawRangeElements_TopOfCylinder;					//Parameter to pass to glDrawRangeElements
	GLuint	End_DrawRangeElements_TopOfCylinder;						//Parameter to pass to glDrawRangeElements
	GLuint	Start_DrawRangeElements_BottomOfCylinder;					//Parameter to pass to glDrawRangeElements
	GLuint	End_DrawRangeElements_BottomOfCylinder;					//Parameter to pass to glDrawRangeElements

	//Index related
	GLint	StartIndexIn_pIndex_BodyOfCylinder, EndIndexIn_pIndex_BodyOfCylinder;		//End-1 gives the last index
	GLint	StartIndexIn_pIndex_TopOfCylinder, EndIndexIn_pIndex_TopOfCylinder;			//End-1 gives the last index
	GLint	StartIndexIn_pIndex_BottomOfCylinder, EndIndexIn_pIndex_BottomOfCylinder;	//End-1 gives the last index

	GLint	TotalIndex_BodyOfCylinder;									//Parameter to pass to glDrawRangeElements
	GLint	TotalIndex_TopOfCylinder;									//Parameter to pass to glDrawRangeElements
	GLint	TotalIndex_BottomOfCylinder;								//Parameter to pass to glDrawRangeElements

	GLushort	*pIndex16Bit_BodyOfCylinder;							//Parameter to pass to glDrawRangeElements. Pointer to pIndex16Bit.
	GLushort	*pIndex16Bit_TopOfCylinder;								//Parameter to pass to glDrawRangeElements. Pointer to pIndex16Bit.
	GLushort	*pIndex16Bit_BottomOfCylinder;							//Parameter to pass to glDrawRangeElements. Pointer to pIndex16Bit.

	GLuint	*pIndex32Bit_BodyOfCylinder;								//Parameter to pass to glDrawRangeElements. Pointer to pIndex32Bit.
	GLuint	*pIndex32Bit_TopOfCylinder;									//Parameter to pass to glDrawRangeElements. Pointer to pIndex32Bit.
	GLuint	*pIndex32Bit_BottomOfCylinder;								//Parameter to pass to glDrawRangeElements. Pointer to pIndex32Bit.

	//Vertex related
	GLint	StartIndexIn_pVertex_BodyOfCylinder, EndIndexIn_pVertex_BodyOfCylinder;		//End-1 gives the last vertex
	GLint	StartIndexIn_pVertex_TopOfCylinder, EndIndexIn_pVertex_TopOfCylinder;		//End-1 gives the last vertex
	GLint	StartIndexIn_pVertex_BottomOfCylinder, EndIndexIn_pVertex_BottomOfCylinder;	//End-1 gives the last vertex
	
	
	GLint	TotalVertex_BodyOfCylinder;
	GLint	TotalVertex_TopOfCylinder;
	GLint	TotalVertex_BottomOfCylinder;

	GLfloat	*pVertex_BodyOfCylinder;								//Pointer to pVertex where body starts
	GLfloat	*pVertex_TopOfCylinder;									//Pointer to pVertex where top starts
	GLfloat	*pVertex_BottomOfCylinder;								//Pointer to pVertex where bottom starts
};

//PURPOSE:	For use with function glhSpheref2
struct glhSphereObject2 : public glhCommonObject2
{
public:
	GLfloat			RadiusA, RadiusB, RadiusC;				//A is in the x direction, B is in the y direction, C is in the z direction
	GLint			Stacks;									//Number of divisions in the Theta direction
	GLint			Slices;									//Number of divisions in the Phi direction

	GLfloat			ScaleFactorS[8], ScaleFactorT[8];		//For texcoord

	
	GLuint			Start_DrawRangeElements;				//Parameter to pass to glDrawRangeElements
	GLuint			End_DrawRangeElements;					//Parameter to pass to glDrawRangeElements
};

//PURPOSE:	For use with function glhPartialSpheref2
struct glhPartialSphereObject2 : public glhSphereObject2
{
	GLint	StartingStack;									//A value from 0 to Stacks-1. Should be <= to EndingStack
	GLint	EndingStack;									//A value from 0 to Stacks-1. Should be >= to StartingStack
};


//HOW TO USE :
//Read the comment for each function like glhCreateCubef2, and it is explained and example code given



//PURPOSE:	Generate the index, vertex and possibly other attributes for rendering a cube.
//			The cube will be centered at origin, with no rotation.
//			Each vertex can have its own normal, its own texcoord, its own tangents and binormals.
//
//PARAMETERS:
//			A glhCubeObject2 must be passed to this function.
//			Width : width of cube in x, >0.0
//			Height : height of cube in y >0.0
//			Length : length of cube in z >0.0
//			WidthDivision : the number of division in x, >0
//			HeightDivision : the number of division in y, >0
//			LengthDivision : the number of division in z, >0
//			AverageNormals : GL_TRUE or GL_FALSE. If GL_TRUE, normals are averaged, if GL_FALSE, it's as if cube has face normals.
//			                 ONLY GL_FALSE works.
//			TotalIndex : Will receive number of indices. Must not be NULL.
//			IndexFormat : GLH_INDEXFORMAT_16BIT or GLH_INDEXFORMAT_32BIT
//			pIndex16Bit : If indexFormat == GLH_INDEXFORMAT_16BIT
//			              Each triplet of indices makes a triangle.
//			              **** It's possible that if many indices are created (>2^16) then
//			              **** pindex32Bit will be used instead, but this is unlikely to happen.
//			pIndex32Bit : If indexFormat == GLH_INDEXFORMAT_32BIT
//			              Each triplet of indices makes a triangle.
//			VertexCount : Will receive the number of vertices.
//			pVertex : The vertices.
//			TexCoordStyle : Array of 8 GLint
//			                If texCoordStyle[X]==0, then memory is reserved for texcoords, nothing is written to the array.
//			                If texCoordStyle[X]==1, then texcoords are computed for each vertex so that each face gets an image.
//
//RETURN:
//			glhGetError returns GLH_ERROR_OUT_OF_MEMORY if it can't reserve memory with new[] operator.
//			glhGetError returns GLH_ERROR_INVALID_PARAM if one of the parameters is wrong.
//			-1 on error.
//			1 for success.
//
//HOW TO USE:
//glhCubeObject2 Cube;
//memset(&Cube, 0, sizeof(glhCubeObject2));
//Cube.Width=1.0; Cube.Height=1.0; Cube.Length=1.0;
//Cube.WidthDivision=1; Cube.HeightDivision=1; Cube.LengthDivision=1;
//Cube.AverageNormals=GL_FALSE;
//Cube.IndexFormat=GLH_INDEXFORMAT_16BIT;
//Cube.VertexFormat=GLHVERTEXFORMAT_VNT;
//Cube.TexCoordStyle[0]=1;
//
//glhCreateCubef2(&Cube);
//
//HOW TO RENDER (You might want to use VBO, I'm just using VA here):
//glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D, TextureID);
//
//glVertexPointer(3, GL_FLOAT, sizeof(GLHVertex_VNT), Cube.pVertex);
//uint mypointer=(uint)Cube.pVertex;
//mypointer+=12;
//glNormalPointer(GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//mypointer+=12;
//glTexCoordPointer(2, GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//
//glDrawRangeElements(GL_TRIANGLES, Cube.Start_DrawRangeElements, Cube.End_DrawRangeElements,
//    Cube.TotalIndex, GL_UNSIGNED_SHORT, Cube.pIndex16Bit);
//
//and to deallocate, call glhDeleteCubef2(&Cube);
GLint GLHLIB_API glhCreateCubef2(glhCubeObject2 *pcube);

//PURPOSE:	Delete the arrays allocated with glhCreateCubef2.
//
//RETURN:
//			Always 1.
GLint GLHLIB_API glhDeleteCubef2(glhCubeObject2 *pcube);


//PURPOSE:	Generate the index, vertex and possibly other attributes for rendering a cylinder.
//			The cylinder will be centered at origin, with no rotation, its main axis will be about the z-axis.
//			Each vertex can have its own normal, its own texcoord, its own tangents and binormals.
//
//PARAMETERS:
//			RadiusA : Top radius of cylinder, >0.0
//			RadiusB : Bottom radius of cylinder, >0.0
//			Height : Height of cylinder in z >0.0
//			Stacks : Think of it like layers of a cake. >=1
//			Slices : Think of it like sections of a cake. >=3
//			AverageNormals : Not used for now.
//			TotalIndex : Will receive number of indices. Must not be NULL.
//			IndexFormat : GLH_INDEXFORMAT_16BIT or GLH_INDEXFORMAT_32BIT
//			pIndex16Bit : If indexFormat == GLH_INDEXFORMAT_16BIT
//			              Each triplet of indices makes a triangle.
//			              **** It's possible that if many indices are created (>2^16) then
//			              **** pindex32Bit will be used instead, but this is unlikely to happen.
//			pIndex32Bit : If indexFormat == GLH_INDEXFORMAT_32BIT
//			              Each triplet of indices makes a triangle.
//			VertexCount : Will receive the number of vertices.
//			pVertex : The vertices.
//			TexCoordStyle : Array of 8 GLint
//			                If texCoordStyle[X]==0, then memory is reserved for texcoords, nothing is written to the array.
//			                If texCoordStyle[X]==1, the default wrap around cylinder, with one on top and one on bottom centered.
//			                                        The body will have texture wrapped around once.
//			ScaleFactorS and ScaleFactorT : Array of 8 GLfloat. Scale factor in s and t direction.
//
//			All other variables in glhCylinderObject are self explanatory. Here are some examples:
//			Start_DrawRangeElements_BodyOfCylinder : a variable to pass to glDrawRangeElements
//			                                         for rendering the body of the cylinder.
//			pVertex_BodyOfCylinder : A pointer to pVertex. This points to the start of the body.
//
//RETURN:
//			glhGetError returns GLH_ERROR_OUT_OF_MEMORY if it can't reserve memory with new[] operator.
//			glhGetError returns GLH_ERROR_INVALID_PARAM if one of the parameters is wrong.
//			-1 on error.
//			1 for success.
//
//HOW TO USE:
//glhCylinderObject2 Cylinder;
//memset(&Cylinder, 0, sizeof(glhCylinderObject2));
//Cylinder.IsThereATop=TRUE; Cylinder.IsThereABottom=TRUE;
//Cylinder.RadiusA=1.0; Cylinder.RadiusB=1.0; Cylinder.Height=1.0;
//Cylinder.Stacks=10; Cylinder.Slices=10;
//Cylinder.IndexFormat=GLH_INDEXFORMAT_16BIT;
//Cylinder.VertexFormat=GLHVERTEXFORMAT_VNT;
//Cylinder.TexCoordStyle[0]=1;
//Cylinder.ScaleFactorS[0]=Cylinder.ScaleFactorT[0]=1.0;
//
//glhCreateCylinderf2(&Cylinder);
//
//HOW TO RENDER (You might want to use VBO, I'm just using VA here):
//glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D, TextureID);
//
//glVertexPointer(3, GL_FLOAT, sizeof(GLHVertex_VNT), Cylinder.pVertex);
//uint mypointer=(uint)Cylinder.pVertex;
//mypointer+=12;
//glNormalPointer(GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//mypointer+=12;
//glTexCoordPointer(2, GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//
//IF YOU WANT TO RENDER THE ENTIRE CYLINDER
//glDrawRangeElements(GL_TRIANGLES, Cylinder.Start_DrawRangeElements, Cylinder.End_DrawRangeElements,
//	Cylinder.TotalIndex, GL_UNSIGNED_SHORT, Cylinder.pIndex16Bit);
//
//IF YOU WANT TO RENDER THE BODY, THEN THE TOP, THEN BOTTOM, make 3 calls to glDrawRangeElements
//glDrawRangeElements(GL_TRIANGLES, Cylinder.Start_DrawRangeElements_BodyOfCylinder, Cylinder.End_DrawRangeElements_BodyOfCylinder,
//	Cylinder.TotalIndex_BodyOfCylinder, GL_UNSIGNED_SHORT, Cylinder.pIndex16Bit_BodyOfCylinder);
//
//glDrawRangeElements(GL_TRIANGLES, Cylinder.Start_DrawRangeElements_TopOfCylinder, Cylinder.End_DrawRangeElements_TopOfCylinder,
//	Cylinder.TotalIndex_TopOfCylinder, GL_UNSIGNED_SHORT, Cylinder.pIndex16Bit_TopOfCylinder);
//
//glDrawRangeElements(GL_TRIANGLES, Cylinder.Start_DrawRangeElements_BottomOfCylinder, Cylinder.End_DrawRangeElements_BottomOfCylinder,
//	Cylinder.TotalIndex_BottomOfCylinder, GL_UNSIGNED_SHORT, Cylinder.pIndex16Bit_BottomOfCylinder);
//
//
//and to deallocate, call glhDeleteCylinderf2(&Cylinder);
GLint GLHLIB_API glhCreateCylinderf2(glhCylinderObject2 *pcylinder);

//PURPOSE:	Delete the arrays allocated with glhCreateCylinderf2.
//
//RETURN:
//			Always 1.
GLint GLHLIB_API glhDeleteCylinderf2(glhCylinderObject2 *pcylinder);


//PURPOSE:	Generate the index, vertex and possibly other attributes for rendering a sphere.
//			The sphere will be centered at origin, with no rotation, its main axis will be about the z-axis.
//			Each vertex can have its own normal, its own texcoord, its own tangents and binormals.
//
//PARAMETERS:
//			RadiusA : In x direction, >0.0
//			RadiusB : In y direction, >0.0
//			RadiusC : In z direction, >0.0
//			Stacks : Think of it like layers of a cake. >=3
//			Slices : Think of it like sections of a cake. >=3
//			AverageNormals : Not used for now.
//			TotalIndex : Will receive number of indices. Must not be NULL.
//			IndexFormat : GLH_INDEXFORMAT_16BIT or GLH_INDEXFORMAT_32BIT
//			pIndex16Bit : If indexFormat == GLH_INDEXFORMAT_16BIT
//			              Each triplet of indices makes a triangle.
//			              **** It's possible that if many indices are created (>2^16) then
//			              **** pindex32Bit will be used instead, but this is unlikely to happen.
//			pIndex32Bit : If indexFormat == GLH_INDEXFORMAT_32BIT
//			              Each triplet of indices makes a triangle.
//			VertexCount : Will receive the number of vertices.
//			pVertex : The vertices.
//			TexCoordStyle : Array of 8 GLint
//			                If texCoordStyle[X]==0, then memory is reserved for texcoords, nothing is written to the array.
//			                If texCoordStyle[X]==1, the default wrap around sphere, with one on top and one on bottom centered.
//			                                        The body will have texture wrapped around once.
//			ScaleFactorS and ScaleFactorT : Array of 8 GLfloat. Scale factor in s and t direction.
//
//
//RETURN:
//			glhGetError returns GLH_ERROR_OUT_OF_MEMORY if it can't reserve memory with new[] operator.
//			glhGetError returns GLH_ERROR_INVALID_PARAM if one of the parameters is wrong.
//			-1 on error.
//			1 for success.
//
//HOW TO USE:
//glhSphereObject2 Sphere;
//memset(&Sphere, 0, sizeof(glhSphereObject2));
//Sphere.RadiusA=1.0; Sphere.RadiusB=1.0; Sphere.RadiusC=1.0;
//Sphere.Stacks=10; Sphere.Slices=10;
//Sphere.IndexFormat=GLH_INDEXFORMAT_16BIT;
//Sphere.VertexFormat=GLHVERTEXFORMAT_VNT;
//Sphere.TexCoordStyle[0]=1;
//Sphere.ScaleFactorS[0]=Sphere.ScaleFactorT[0]=1.0;
//
//glhCreateSpheref2(&Sphere);
//
//HOW TO RENDER (You might want to use VBO, I'm just using VA here):
//glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D, TextureID);
//
//glVertexPointer(3, GL_FLOAT, sizeof(GLHVertex_VNT), Sphere.pVertex);
//uint mypointer=(uint)Sphere.pVertex;
//mypointer+=12;
//glNormalPointer(GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//mypointer+=12;
//glTexCoordPointer(2, GL_FLOAT, sizeof(GLHVertex_VNT), (uint *)mypointer);
//glDrawRangeElements(GL_TRIANGLES, Sphere.Start_DrawRangeElements, Sphere.End_DrawRangeElements,
//	Sphere.TotalIndex, GL_UNSIGNED_SHORT, Sphere.pIndex16Bit);
//
//
//and to deallocate, call glhDeleteSpheref2(&Sphere);
GLint GLHLIB_API glhCreateSpheref2(glhSphereObject2 *psphere);

//PURPOSE:	Delete the arrays allocated with glhCreateSpheref.
//
//RETURN:
//			Always 1.
GLint GLHLIB_API glhDeleteSpheref2(glhSphereObject2 *psphere);



/*Block 21 -end*/


/*Block 22 -start*/
//****************************************************************************
//COLOR SPACE CONVERSION

//PURPOSE:	Using red, green and blue, compute hue, saturation and value.
void GLHLIB_API glhComputeHSVWithRGBf(GLfloat &hue, GLfloat &saturation, GLfloat &value, GLfloat red, GLfloat green, GLfloat blue);

//PURPOSE:	Using hue, saturation and value, compute red, green and blue.
void GLHLIB_API glhComputeRGBWithHSVf(GLfloat &red, GLfloat &green, GLfloat &blue, GLfloat hue, GLfloat saturation, GLfloat value);

//PURPOSE:	Using hue, saturation and value, compute red, green and blue.
//			Write it to a 32 bit uint. Format is 0xAARRGGBB.
void GLHLIB_API glhComputeBGRAWithHSVfub(GLuint &bgraColor, GLfloat hue, GLfloat saturation, GLfloat value, GLfloat alpha);

//PURPOSE:	Using hue, saturation and value, compute red, green and blue.
//			Write it to a 32 bit uint. Format is 0xAABBGGRR.
void GLHLIB_API glhComputeRGBAWithHSVfub(GLuint &rgbaColor, GLfloat hue, GLfloat saturation, GLfloat value, GLfloat alpha);

//PURPOSE:	Using red, green and blue, compute hue, saturation and value.
//			bgraColor is in 0xAARRGGBB format.
void GLHLIB_API glhComputeHSVWithBGRAubf(GLfloat &hue, GLfloat &saturation, GLfloat &value, GLfloat &alpha, GLuint bgraColor);

//PURPOSE:	Using red, green and blue, compute hue, saturation and value.
//			bgraColor is in 0xAABBGGRR format.
void GLHLIB_API glhComputeHSVWithRGBAubf(GLfloat &hue, GLfloat &saturation, GLfloat &value, GLfloat &alpha, GLuint rgbaColor);


/*Block 22 -end*/

/*Block 23 -start*/
//****************************************************************************
//INTERSECTION TESTING

//PURPOSE:	Test to see if a ray intersects a triangle.
//
//PARAMETERS:
//			Start point of ray is rayPoint1 (xyz)
//			rayDirection need no be normalized (xyz)
//			rayDirectionLengthSquared = rayDirection DOT rayDirection
//			trianglePoint1, trianglePoint2 are the first 2 vertices (xyz)
//			triangleVector1 is trianglePoint2-trianglePoint1 (xyz)
//			triangleVector2 is triangleVector3-triangleVector1 (xyz)
//			triangleVector1LengthSquared = triangleVector1 DOT triangleVector1
//			triangleVector2LengthSquared = triangleVector2 DOT triangleVector2
//			triangleVector1_DOT_triangleVector2 = triangleVector1 DOT triangleVector2
//			pointOfIntersection receives the intersection point (xyz)
//
//RETURN:
//			1 if intersection detected, and pointOfIntersection receives the intersection point
//			0 if no intersection
GLint GLHLIB_API glhDoesRayCrossTrianglef(GLfloat *rayPoint1, GLfloat *rayDirection, GLfloat rayDirectionLengthSquared,
												GLfloat *trianglePoint1, GLfloat *trianglePoint2,
												GLfloat *triangleVector1, GLfloat *triangleVector2,
												GLfloat triangleVector1LengthSquared, GLfloat triangleVector2LengthSquared,
												GLfloat triangleVector1_DOT_triangleVector2,
												GLfloat *pointOfIntersection);


/*Block 23 -end*/

/*Block 24 -start*/
//****************************************************************************
//PROCESSOR SECTION

//PURPOSE:	1 for yes, 0 for no.
//			Call glhDoesProcessorSupportSSE first, then call glhDoesProcessorSupportSSE and/or glhDoesProcessorSupportSSE2
GLint GLHLIB_API glhDoesProcessorSupportMMX();
GLint GLHLIB_API glhDoesProcessorSupportSSE();
GLint GLHLIB_API glhDoesProcessorSupportSSE2();
GLint GLHLIB_API glhDoesProcessorSupport3DNow();
GLint GLHLIB_API glhDoesProcessorSupport3DNowExtended();
GLint GLHLIB_API glhDoesOSSupportSSE();

//PURPOSE:	Get information on the CPU using the Windows registry
//			All pointers must be valid.
//			If error occurs while trying to get info from registry, then any of the parameters can be a empty string.
void GLHLIB_API glhGetProcessorInfo(char *pVendor, char *pName, char *pSpeedInMHz);

/*Block 24 -end*/

/*Block 25 -start*/
//****************************************************************************
//SHADER CODE RELATED

//PURPOSE:	Convert a shader from one format into another.
//			D3D pixel shader to GL fragment program
//			D3D vertex shader to GL vertex program
//			For example, from Direct3D ps2.0 to OpenGL ARBfp1.0
//			**** This function can be considered obsolete because for GL, it's own
//			**** high level shader is prefered, called GLSL
//			**** In the future, I may decide to add support for converting D3D low
//			**** level shader to GLSL and convert GL low level shaders to GLSL
//
//PARAMETERS:
//			shaderTypeIn  : should be one of the defines starting with GLH_SHADERTYPE_
//			                GLH_SHADERTYPE_PS_2_0
//			                GLH_SHADERTYPE_PS_1_4
//			                GLH_SHADERTYPE_VS_1_1
//			                GLH_SHADERTYPE_VS_2_0
//			pshaderTextIn : contains a NULL terminated ASCII text of the shader.
//			shaderTypeOut  : should be one of the defines starting with GLH_SHADERTYPE_
//			                 GLH_SHADERTYPE_ARBFP_1_0
//			                 GLH_SHADERTYPE_ARBVP_1_0
//			pshaderTextOut : You should allocate some space for this function to write the output string
//			                 Allocate twice the amount as pshaderTextIn
//			maxLengthOfShaderTextOut : The actual size of pshaderTextOut in bytes.
//
//RETURN:
//			1 for success
//			-1 if not yet implemented
GLint GLHLIB_API glhTranslateShader(GLint shaderTypeIn, const char *pshaderTextIn, GLint shaderTypeOut, char *pshaderTextOut, GLint maxLengthOfShaderTextOut);


/*Block 25 -end*/


/*Block 26 -start*/
//****************************************************************************
//MEMORY USAGE RELATED

//PURPOSE:	Get the max mipmap count based on :
//
//PARAMETERS:
//			[out] count : receives single GLint, which is the mipmap count
//			[in] target : GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, GL_TEXTURE_CUBE_MAP
//			              RECT textures can't be mipmapped.
//			[in] width : for 1D, 2D, 3D, cube. >0
//			[in] height : for 2D, cube, otherwise ignored. >0
//			[in] depth : for 3D, otherwise ignored. >0
//
//RETURN:
//			1 for success
//			-1 if target is bad
//			-2 if components is bad
//			If width, height or depth are 0 or less when they matter total receives 0
//			and function returns 1.
GLint GLHLIB_API glhGetMaxMipmapCount(GLint *count, GLenum target, GLint width, GLint height, GLint depth);

//PURPOSE:	Computes memory consumption of a texture in bytes
//			See also glhGetMaxMipmapCount(GLint *count, GLenum target, GLint width, GLint height, GLint depth)
//			Example :
//			GLint mipmapCount, totalBytes;
//			result=glhGetMaxMipmapCount(&mipmapCount, GL_TEXTURE_2D, width, height, depth);
//			result=glhMemoryUsageWithMipmaps(&totalBytes, GL_TEXTURE_2D, GL_RGBA8, 4, width, height, depth, 0, mipmapCount-1);
//			
//
//PARAMETERS:
//			[out] total : receives single GLint, count in bytes
//			[in] target : GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, GL_TEXTURE_CUBE_MAP
//			              RECT textures can't be mipmapped.
//			[in] components :
//					GL_ALPHA4
//					GL_ALPHA8
//					GL_ALPHA12
//					GL_ALPHA16
//					GL_LUMINANCE4
//					GL_LUMINANCE8
//					GL_LUMINANCE12
//					GL_LUMINANCE16
//					GL_LUMINANCE4_ALPHA4
//					GL_LUMINANCE6_ALPHA2
//					GL_LUMINANCE8_ALPHA8
//					GL_LUMINANCE12_ALPHA4
//					GL_LUMINANCE12_ALPHA12
//					GL_LUMINANCE16_ALPHA16
//					GL_INTENSITY4
//					GL_INTENSITY8
//					GL_INTENSITY12
//					GL_INTENSITY16
//					GL_R3_G3_B2
//					GL_RGB4
//					GL_RGB5
//					GL_RGB8
//					GL_RGB10
//					GL_RGB12
//					GL_RGB16
//					GL_RGBA2
//					GL_RGBA4
//					GL_RGB5_A1
//					GL_RGBA8
//					GL_RGB10_A2
//					GL_RGBA12
//					GL_RGBA16
//					GL_DEPTH_COMPONENT16
//					GL_DEPTH_COMPONENT24
//					GL_DEPTH_COMPONENT32
//					GL_COMPRESSED_RGB_S3TC_DXT1_EXT (See EXT_texture_compression_s3tc, same as MS DXTC)
//					GL_COMPRESSED_RGBA_S3TC_DXT1_EXT (See EXT_texture_compression_s3tc, same as MS DXTC)
//					GL_COMPRESSED_RGBA_S3TC_DXT3_EXT (See EXT_texture_compression_s3tc, same as MS DXTC)
//					GL_COMPRESSED_RGBA_S3TC_DXT5_EXT (See EXT_texture_compression_s3tc, same as MS DXTC)
//					GL_RGBA_FLOAT32_ATI same as GL_RGBA32F_ARB
//					GL_RGB_FLOAT32_ATI same as GL_RGB32F_ARB
//					GL_ALPHA_FLOAT32_ATI same as GL_ALPHA32F_ARB
//					GL_INTENSITY_FLOAT32_ATI same as GL_INTENSITY32F_ARB
//					GL_LUMINANCE_FLOAT32_ATI same as GL_LUMINANCE32F_ARB
//					GL_LUMINANCE_ALPHA_FLOAT32_ATI same as GL_LUMINANCE_ALPHA32F_ARB
//					GL_RGBA_FLOAT16_ATI same as GL_RGBA16F_ARB
//					GL_RGB_FLOAT16_ATI same as GL_RGB16F_ARB
//					GL_ALPHA_FLOAT16_ATI same as GL_ALPHA16F_ARB
//					GL_INTENSITY_FLOAT16_ATI same as GL_INTENSITY16F_ARB
//					GL_LUMINANCE_FLOAT16_ATI same as GL_LUMINANCE16F_ARB
//					GL_LUMINANCE_ALPHA_FLOAT16_ATI same as GL_LUMINANCE_ALPHA16F_ARB
//			[in] dataAlignment : should be 1, 2, 4, 8, .... (Typically 1 or 4)
//			[in] width : for 1D, 2D, 3D, cube. >0
//			[in] height : for 2D, cube, otherwise ignored. >0
//			[in] depth : for 3D, otherwise ignored. >0
//			[in] lowRange : starting from level 0 mipmap inclusive
//			[in] highRange : up to the highest mipmap level inclusive, counting from the base level=0
//			                 Use glhGetMaxMipmapCount to get the max number and pass count-1 to this function
//			                 to get all mipmap levels
//
//RETURN:
//			1 for success
//			-1 if target is bad
//			-2 if components is bad
//			If width, height or depth are 0 or less when they matter total receives 0
//			and function returns 1.
//
//ISSUE:	Certain formats like GL_LUMINANCE4 and others specify partial byte count
//			and this function counts bytes as integers.
//			I decided to ceil such formats.
//			Example : GL_LUMINANCE4 is 0.5 bytes and becomes 1 byte.
GLint GLHLIB_API glhMemoryUsageWithMipmaps(GLint *total, GLenum target, GLint components, GLint dataAlignment, GLint width, GLint height, GLint depth, GLint lowRange, GLint highRange);

//PURPOSE:	Estimate how much VRAM the OpenGL surface is using
//			The algorithm used is :
//			if((depthBufferBits==24)&&(depthAndStencilTogether==FALSE))
//				otherbuffer1=32;
//			else
//				otherbuffer1=depthBufferBits;
//
//			if((depthBufferBits==24)&&(depthAndStencilTogether==TRUE)&&(stencilBufferBits==8))
//				otherbuffer2=0;
//			else
//				otherbuffer2=stencilBufferBits;
//
//			if(backBufferCount==0)
//				backBufferCount++;
//
//			sum = (color_buffer + otherbuffer1 + otherbuffer2) * backBufferCount;
//			if(includeFrontBuffer)
//				sum += bitsPerPixel_Color_FrontBuffer;
//
//PARAMETERS:
//			[out] memoryCount : VRAM usage, in bytes
//			[in] width : width of frame buffer
//			[in] height : height of frame buffer
//			[in] includeFrontBuffer : count the front buffer as well? TRUE or FALSE
//			[in] bitsPerPixel_Color_FrontBuffer : 16, 24, 32. If includeFrontBuffer=FALSE, this doesn't matter
//			[in] bitsPerPixel_Color : For the back buffer. There could be many back buffers. 16, 24, 32
//			[in] depthAndStencilTogether : Is it a merged z-buffer and stencil buffer? TRUE or FALSE
//			[in] depthBufferBits : 16, 24, 32
//			[in] stencilBufferBits : 0, 8, 16, 24, 32
//			[in] backBufferCount : How many backbuffers have been created?
//			                       0 and 1 mean the same. There is at least 1 back buffer.
//			                       2 means tripple buffering
//			                       3 and above is also possible but sure if any GPU supports it
//
//RETURN:
//			1 for success
//			-1 if an unexpectant value was passed
GLint GLHLIB_API glhComputeFrameBufferUsage(GLint *memoryCount, GLint width, GLint height, GLint includeFrontBuffer, GLint bitsPerPixel_Color_FrontBuffer, GLint bitsPerPixel_Color, GLint depthAndStencilTogether, GLint depthBufferBits, GLint stencilBufferBits, GLint backBufferCount);


/*Block 26 -end*/



#ifdef __cplusplus
}
#endif


#endif //_GLHLIB_H_