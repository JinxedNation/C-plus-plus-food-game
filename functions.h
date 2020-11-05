#pragma once
#include <math.h>
#include <GL/glut.h>
#include <time.h>
#include <SDL.h>

//#include <windows.h> // only used if mouse is required (not portable)
#include "camera.h"
#include "texturedPolygons.h"
#include "Object.h"
#include "OBJLoader.h"
#include "FrameTimer.h"
#include "NewSound.h"

/**
* @file functions
* @brief Holds the functions that are not help in a class
*
* @author Shay Leary
* @version 01
* @date March 2005
*
* @author Team Chris
* @version 02
* @date 14/09/2020
*
*/

#define PI 3.1415962654

// TEXTURE IMAGE AXISES
#define XY		0
#define XZ		1
#define YZ		2
#define YZ_FLIP 3
#define XY_FLIP 4

// PLAIN TYPES
#define FLAT_PLAIN	0
#define XY_PLAIN	1
#define ZY_PLAIN	2

// TEXTURES
// Grass Textures
#define GRASS						1
#define GRASS_2						2
#define GRASS_HILL					3
// Pavement Textures
#define PAVEMENT					4
#define PAVEMENT_TOP				5
#define PAVEMENTSIDE_LEFT			6
#define PAVEMENTSIDE_RIGHT			7
#define PAVEMENTSIDE_TOP			8
#define PAVEMENT_CORNER_1			9
#define PAVEMENT_CORNER_2			10
#define PAVEMENT_FLIP				11
#define PAVEMENT_TOP_FLIP			12
#define PAVEMENT_16					13
#define DOORPAVE_1					14
// Wall Brick Textures
#define WALL_BRICK_YZ				15
#define WALL_BRICK_XY				16
#define WALL_BRICK_XY_87WIDTH		17
#define WALL_BRICK_GAP_YZ			18
#define WALL_BRICK_GAP2_YZ			19
#define	WALL_BRICK_USD_YZ			20
#define WALL_BRICK_XY_END			21
#define WALL_BRICK_YZ_END			22
#define	WALL_GAP_1					23
#define WALL_BRICK_3_4				24
#define SHADOW_BRICK				25
#define WALL_BRICK_SEC_SIGN			216
// Window Post Textures
#define WINDOWPOST_CHANC_FRONT		26
#define WINDOWPOST_CHANC_RIGHT	    27
#define WINDOWPOST_CHANC_LEFT	    28
#define WINDOWLEDGE_CHANC_FRONT		29
#define WINDOWLEDGE_CHANC_TOP		30
#define WINDOWPOST_PHYSSCI_FRONT	31
#define WINDOWPOST_PHYSSCI_RIGHT	32
#define WINDOWPOST_PHYSSCI_LEFT		33
#define	WINDOWPOST_LIB_FRONT		34
#define	WINDOWPOST_LIB_LEFT			35
#define	WINDOWPOST_LIB_RIGHT		36
// Door Post Textures
#define DOOR_POST_SECURITY			37
// Window Ledge Textures
#define WINDOWLEDGE_PS_FRONT		38
#define WINDOWLEDGE_PS_TOP			39
#define WINDOWLEDGE_PS_BOTT			40
#define WINDOWLEDGE_LIB_A			41
#define WINDOWLEDGE_LIB_B			42
#define WINDOWLEDGE_LIB_TOP_A		43
#define WINDOWLEDGE_LIB_TOP_B		44
#define WINDOW_LEDGE_END_1			45
#define WINDOW_LEDGE_END_2			46
// Main Post Textures
#define	MAIN_POST					47
#define	MAIN_POST_2					48
// Door Post Textures
#define DOOR_POST_CHANC				49
#define DOOR_SIDEPOST_CHANC			50
#define DOOR_POST_LIB				215
// Coloured Posts Textures
#define PURPLE_POST					51
#define PURPLE_POSTSIDE				52
#define RED_POST					53
#define RED_POSTSIDE				54
// Roof Textures
#define ROOF_TOP					55
#define ROOF_TOP_LIB				56
#define ROOF_PLANKS					57
#define ROOF_BEAM_1					58
#define ROOF_PLANKS_2				59
#define ROOF_BEAM_2					60
#define BELOW_ROOF_FILL				61
#define ROOF_BEAM_3					62
#define ROOF_BEAM_4					63
#define ROOF_BEAM_3_TOP				64
// KBLT Textures
#define KBLT						65
#define KBLT_EDGE					66
#define KBLT_EDGE_2					67
#define KBLT_EDGE_CORNER			68
#define KBLT_SIDE_1					69
#define KBLT_SIDE_2					70
// Sign and Other Textures
#define NEXUS_SIGN					71
#define NEXUS_SIDE					72
#define SECURITY_SIGN				73
#define SECURITY_SIGN_2				74
#define SIGN_1						75
#define SIGN_1_SIDE_1				76
#define SIGN_1_SIDE_2				77
#define SIGN_2						78
#define SIGN_2_SIDE					79
#define PSC_SIGN					80
#define PSC_SIGN_2					81
#define CO_SIGN						82
#define STA_TRAVEL					83
#define STA_TRAVEL_EDGE				84
#define STA_TRAVEL_BRACKET			85
#define STA_TRAVEL_2				86
#define STA_TRAVEL_BOTTOM			87
#define TOILET_MEN					88
#define TOILET_WOMEN				89
#define GS_SIGN						90
#define GS_SIGN_2					91
#define GS_SIGN_EDGE				92
#define MAP_2						93
#define GLASS_BOARD					94
#define GLASS_BOARD_2				95
#define GLASS_BOARD_3				96
#define GLASS_B_SIDE				97
#define RUSTY_MAN					98
#define NO_SMOKE_SIGN				99
#define CARPET						100
// Drinks Machine Textures
#define DRINKS_SIDE					101
#define DRINKS_TOP					102
#define DRINKS_EDGE					103
#define DRINKS_SIDE_2				104
#define COKE_MACHINE				105
#define COFFEE_MACHINE				106
#define SWEET_MACHINE				107
#define MACHINE_SIDES				108
#define MACHINE_SIDES_2				109
// Telephone Box Textures
#define TELEPHONE_BACK				110
#define TELEPHONE_FRONT				111
#define TELEPHONE_SIDE_1			112
#define TELEPHONE_FRONT_2			113
#define TELEPHONE_MAIN_SIDE			114
#define TELEPHONE_TOP_1				115
#define TELEPHONE_SIDE_2			116
#define TELEPHONE_TOP_2				117
#define TELEPHONE_BOTTOM			118
#define TELEPHONE_FILL				119
#define TELEPHONE_FRONT_3			120
// Step Textures
#define STEPS_LIBRARY				121
#define STEPS_LIBRARY_TOP			122
#define	STEP_PAVING_1				123
#define	STEP_EDGE					124

// Larger Window and Door Textures Etc
#define WINDOW_1					125
#define WINDOW_2					126
#define WINDOW_3					127
#define WINDOW_4					128
#define WINDOW_5					129
#define WINDOW_6					130
#define WINDOW_7					131
#define WINDOW_8					132
#define WINDOW_9					133
#define WINDOW_10					134
#define WINDOW_11					135
#define WINDOW_12					136
#define WINDOW_13					137
#define WINDOW_14					138
#define WINDOW_14B					139
#define WINDOW_15					140
#define WINDOW_16					141
#define WINDOW_17					142
#define WINDOW_2B					143
#define WINDOW_2C					144
#define WINDOW_2US					145
#define WINDOW_3B					146
#define WINDOW_2USB					147
#define WINDOW_LIB_1				148
#define WINDOW_LIB_1A				149
#define WINDOW_LIB_1B				150
#define WINDOW_LIB_1C				151
#define WINDOW_LIB_US_A				152
#define WINDOW_LIB_US_B				153
#define WINDOW_LIB_DOOR_1			154
#define WINDOW_LIB_DOOR_2			155
#define WINDOW_LIB_LONG				156
#define ENTRANCE					157
#define ENTRANCE_2					158
#define EXIT_EAST					159
#define EXIT_WEST					220
#define CHANC_DOOR_1				160
#define CHANC_DOOR_2				161
#define WINDOW_2D					162
#define WINDOW_2E					163
#define WINDOW_1B					164
#define STEP_WINDOW					221

// Above Window Block Textures
#define ABOVE_WINDOW_BLOCK			165
#define ABOVE_WINDOW_BLOCK_2		166
#define ABOVE_WINDOW_BLOCK_3		167
#define ABOVE_WINDOW_EDGE_3B		168
#define ABOVE_WINDOW_BLOCK_XY_3		169
#define	ABOVE_LIB					170
#define	ABOVE_UNDER_POSTS			171
#define ABOVE_UNDER_POSTS_2			172
#define ABOVE_WINDOW_UNDER_LIB		173
#define ABOVE_WINDOW_BLOCK_CHANC	174
#define ABOVE_WINDOW_EDGE_3B_LIB	175
#define ABOVE_WINDOW_EDGE_4B_LIB	176
#define ABOVE_UNDER_4B				177
#define ABOVE_CHANC_TEXT			178
#define ABOVE_CHANC_TEXT_2			179
#define ABOVE_PHYS_SCI_TEXT			180
#define ABOVE_CHANC_TEXT_3			181
#define ABOVE_LIB_TEXT				182
#define ABOVE_LIB_TEXT_2			183
#define ABOVE_TICKETS_TEXT			184
#define ABOVE_CHANC_EDGE			185
#define TOILET_DOOR_TOP				186
// Light Fitting Textures
#define LIGHT						187
#define	LIGHT_SUPPORT				188
#define	LIGHT_SUPPORT_2				189
// Bench Textures
#define BENCH_TOP					190
#define BENCH_SIDE					191
#define BENCH_SIDE_2				192
#define BENCH_EDGE					193
#define BENCH_EDGE_TOP				194
#define BENCH_EDGE_SIDE				195
#define BENCH_EDGE_TOP_2			196
#define BENCH_EDGE_2				197
#define BENCH_EDGE_3				198
// Ticket Counter and Ledge Textures
#define TICKET_COUNTER_TOP			200
#define TICKET_COUNTER_EDGE			201
#define TICKET_COUNTER_EDGE_2		202
#define TICKET_COUNTER_EDGE_3		203
#define TICKET_LEDGE				204
#define TICKET_LEDGE_EDGE			205
#define TICKET_LEDGE_EDGE_2			206
// Wall by Steps Textures
#define WALL_BRICK_STEPS_TOP		207
#define WALL_BRICK_STEPS			208
#define WALL_BRICK_STEPS_COVER		209
#define WALL_BRICK_STEPS_EDGE		210
#define WALL_BRICK_STEPS_EDGE_2		211
// Extra Textures
#define DRAINPIPE					212
#define COUNTER_TOP					213
#define COUNTER_SIDE				214
// Welcome, Exit and Map Screens
#define MAP							217
#define WELCOME						218
#define EXIT						219
#define NO_EXIT						222

// 223 Next




/**
* @brief Initiallises the settings for the program
*
* @return void
*/
void myinit();

/**
* @brief The display function used by glut, renders everything/calls functions to render things
*
* @return void
*/
void Display();

/**
* @brief Reshapes the screen so that when the window is changed, the program does not stretch
*
* @return void
*/
void reshape(int w, int h);

/**
* @brief Takes keyboard inputs
*
* @return void
*/
void keys(unsigned char key, int x, int y);

/**
* @brief Checks the movment keys
*
* @return void
*/
void movementKeys(int key, int x, int y);

/**
* @brief Checks if a key has been released
*
* @return void
*/
void releaseKey(int key, int x, int y);

/**
* @brief Checks if a key has been released
*
* @return void
*/
void releaseKeys(unsigned char key, int x, int y);

/**
* @brief Checks if the mouse has been clicked
*
* @return void
*/
void Mouse(int button, int state, int x, int y);

/**
* @brief Checks when the mouse has been moved
*
* @return void
*/
void mouseMove(int x, int y);

/**
* @brief Loads in the models used in the program
*
* @return void
*/
void LoadModels();

/**
*
*
*
*/
void LoadLevels();

void LoadFoodObjects();

void DisplayLevel();

void DisplayAi();

void DisplayZones();

void CheckAiCollision();

/**
* @brief Displays all the calls for the student hub (walls, floors, ceilings)
*
* @return void
*/
void DisplayStudentHub();

/**
* @brief Creates the lists that can be called to display the objects in the student hub
*
* @return void
*/
void DrawStudentHub();
/**
* @brief Displays models that have a texture (not used as textures dont work just yet)
*
* @return void
*/
void DisplayTexturedModels();

/**
* @brief Displays models with no textures
*
* @return void
*/
void DisplayNoTextureModels();

void CheckZones();

/**
* @brief Sets the bounding boxes for the walls in the student hub
*
* @return void
*/
void HubBoundingBox();

/**
* @brief Draws all the objects
*
* @return void
*/
void DrawBackdrop();

/**
* @brief Displays lists above window block
*
* @return void
*/
void DisplayAboveWindowBlock();

/**
* @brief Displays the benches
*
* @return void
*/
void DisplayBench();

/**
* @brief Displays walls with brikcs
*
* @return void
*/
void DisplayBricks();

/**
* @brief Displays the posts
*
* @return void
*/
void DisplayChancPosts();

/**
* @brief Displays the cylinders
*
* @return void
*/
void DisplayCylinders();

/**
* @brief Displays the door paving
*
* @return void
*/
void DisplayDoorPaving();

/**
* @brief Displays the door posts
*
* @return void
*/
void DisplayDoorPosts();

/**
* @brief Displays the entrance to the steps
*
* @return void
*/
void DisplayEntranceSteps();

/**
* @brief Displays the extras
*
* @return void
*/
void DisplayExtras();

/**
* @brief Displays the grass
*
* @return void
*/
void DisplayGrass();

/**
* @brief Displays the larger images
*
* @return void
*/
void DisplayLargerTextures();

/**
* @brief Displays posts in front of libary
*
* @return void
*/
void DisplayLibraryPosts();

/**
* @brief Displays main posts
*
* @return void
*/
void DisplayMainPosts();

/**
* @brief Displays the pavement
*
* @return void
*/
void DisplayPavement();

/**
* @brief Displays posts in front of science and physics block
*
* @return void
*/
void DisplayPhysSciPosts();

/**
* @brief Displays the purple posts
*
* @return void
*/
void DisplayPurplePosts();

/**
* @brief Displays the red posts
*
* @return void
*/
void DisplayRedPosts();

/**
* @brief Displays the roof
*
* @return void
*/
void DisplayRoof();

/**
* @brief Displays the steps and its bricks
*
* @return void
*/
void DisplayStepBricks();

/**
* @brief Displays the lights
*
* @return void
*/
void DisplayLights();
void DisplayECL();

/**
* @brief Creates display lists for the textures being used in the program
*
* @return void
*/
void CreateTextureList();
/**
* @brief Creates a display list for the grass
*
* @return void
*/
void DrawGrass();
/**
* @brief Creates a display list for the posts infront of the chancelor building
*
* @return void
*/
void DrawChancPosts();

/**
* @brief Creates a display list for the posts infront of the door
*
* @return void
*/
void DrawDoorPosts();

/**
* @brief Creates a display list for the purple posts
*
* @return void
*/
void DrawPurplePosts();

/**
* @brief Creates a display list for the red posts
*
* @return void
*/
void DrawRedPosts();

/**
* @brief Creates a display list for the main posts
*
* @return void
*/
void DrawMainPosts();

/**
* @brief Creates a display list for the window block
*
* @return void
*/
void DrawAboveWindowBlock();

/**
* @brief Creates a display list for the pavement in front of the door
*
* @return void
*/
void DrawDoorPaving();

/**
* @brief Creates a display list for the posts infront of the physics and science area
*
* @return void
*/
void DrawPhysSciPosts();

/**
* @brief Creates a display list for the posts infront of the libary
*
* @return void
*/
void DrawLibraryPosts();

/**
* @brief Creates a display list for the bricks(walls)
*
* @return void
*/
void DrawBricks();

/**
* @brief Creates a display list for the pavement
*
* @return void
*/
void DrawPavement();

/**
* @brief Creates a display list for the extra things
*
* @return void
*/
void DrawExtras();

/**
* @brief Creates a display list for the  roof
*
* @return void
*/
void DrawRoof();

/**
* @brief Creates a display list for the entrance steps
*
* @return void
*/
void DrawEntranceSteps();

/**
* @brief Creates a display list for larger images
*
* @return void
*/
void DrawLargerTextures();

/**
* @brief Creates a display list for the lights
*
* @return void
*/
void DrawLights();

/**
* @brief Creates a display list for the benches
*
* @return void
*/
void DrawBench();

/**
* @brief Creates a display list for the cylinders
*
* @return void
*/
void DrawCylinders();

/**
* @brief Creates a display list for the roof beams (1)
*
* @return void
*/
void DrawAngledRoofBeam(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);

/**
* @brief Creates a display list for the roof beams (2)
*
* @return void
*/
void DrawAngledRoofBeam2(int listNo, GLdouble x, GLdouble y, GLdouble z, GLdouble beamSize);

/**
* @brief Creates a display list for steps bricks
*
* @return void
*/
void DrawStepBricks();


/**
* @brief Creates a display list for the map
*
* @return void
*/
void DrawMapExit();
void DrawECL();


void BindBridgeWall(GLint LR);
void BindBuildingWall();
void BindWallPosts(GLint LR);


/**
* @brief Increments the frame counter
*
* @return void
*/
void IncrementFrameCount();


/**
* @brief Loads in images to create textures
*
* @return void
*/
void CreateTextures();

/**
* @brief Creates the bounding boxes for shays parts of the world
*
* @return void
*/
void CreateBoundingBoxes();

/**
* @brief Creates the different plains in the world
*
* @return void
*/
void CreatePlains();


/**
* @brief Clears the images and deletes them from memory
*
* @return void
*/
void DeleteImageFromMemory(unsigned char* tempImage);

void CheckItem();

void CheckThrowCollision();

void AddFloorCollisions();

void CreateStarterZone();
void DisplayLevelSelector();

void CheckLevelSelector(int i);

void ChargeThrow();

void LoadSounds();
