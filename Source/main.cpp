/* --------------------------------------- Besm Allah rahman rahim   ----------------------------------------------------
 *
 * Copyright (C) 2011 AllahSoft Std.
 *
 * Bijan Binaee <bijanbina@gmail.com>
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <clutter/clutter.h>

#define WIDTH 600
#define HEIGHT 600
#define SIZE 100
#define DEPTH -100
#define COUNT 36

using namespace std;

int
main (int argc, char *argv[])
{
  ClutterActor *stage = NULL;
	ClutterActor *button[COUNT];
  ClutterGeometry geom = {0, 0, SIZE, SIZE};
  gint i = 0;
	int ColorStep[3] = {6,2,1};
	int start_color = 0;
	if ( argc == 4)
	{
		ColorStep[0] =  atoi(argv[1]);
		ColorStep[1] = atoi(argv[2]);
		ColorStep[2] = atoi(argv[3]);
		cout << "Hi Please Enter Start Color (for all))\n";
		cin >> start_color;
	}
	
  if (clutter_init (&argc, &argv) != CLUTTER_INIT_SUCCESS)
    return 1;
	
  stage = clutter_stage_get_default ();

  clutter_actor_set_size (stage, WIDTH, HEIGHT);

	for ( i = 0 ; i < COUNT ; i++)
	{
		ClutterColor  *buffer_Color =  clutter_color_new( (i + start_color) * ColorStep[0] , (i + start_color) * ColorStep[1], (i + start_color) * ColorStep[2], 255 );
		int k = i / 6;
		ClutterGeometry buffer_geom = {(i % 6) * SIZE, k * SIZE, SIZE, SIZE};
		button[i] = clutter_rectangle_new_with_color (buffer_Color);
		clutter_actor_set_geometry (button[i], &buffer_geom);
		ClutterGeometry *buf_geom;
		/*
		printf("X[%d]:  %f Y : %f\n",i,clutter_actor_get_x (button[i]),clutter_actor_get_y (button[i]));*/
		clutter_actor_show (button[i]);
		clutter_container_add_actor (CLUTTER_CONTAINER (stage), button[i]);
	}
	
  clutter_actor_show_all (stage);

  clutter_main ();

  return 0;
}
