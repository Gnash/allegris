#include "Allegris.h"

using namespace std;


const float FPS = 60;
const float LPS = 60;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *evQueue;
ALLEGRO_TIMER *logicsTimer;
ALLEGRO_TIMER *graphicsTimer;

bool init();

int main(int argc, char **argv)
{
	bool redraw = false;
	
	if (!init()) {
		return -1;
	}

   Game* game = new Game();

	while(1) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(evQueue, &ev);
 
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(ev.any.source == al_get_timer_event_source(logicsTimer)) {
				game->updateLogic();
			}
			else if (ev.any.source == al_get_timer_event_source(graphicsTimer)) {
				redraw = true;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
 
		if(redraw && al_is_event_queue_empty(evQueue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0,0,0));
			game->updateGraphic();
			al_flip_display();
		}
   }
 
   al_destroy_timer(logicsTimer);
   al_destroy_timer(graphicsTimer);
   al_destroy_display(display);
   al_destroy_event_queue(evQueue);

   delete game;
 
   return 0;
}



bool init() {
	al_init();
	al_init_image_addon();
	al_install_keyboard();
 
   display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return false;
   }

   logicsTimer = al_create_timer(1.0 / LPS);
   if(!logicsTimer) {
      fprintf(stderr, "failed to create logics timer!\n");
      return -1;
   }

   graphicsTimer = al_create_timer(1.0 / FPS);
   if(!graphicsTimer) {
      fprintf(stderr, "failed to create graphics timer!\n");
      return -1;
   }
 
   evQueue = al_create_event_queue();
   if(!evQueue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      al_destroy_timer(logicsTimer);
      al_destroy_timer(graphicsTimer);
      return -1;
   }

   al_register_event_source(evQueue, al_get_display_event_source(display));
 
   al_register_event_source(evQueue, al_get_timer_event_source(logicsTimer));
   
   al_register_event_source(evQueue, al_get_timer_event_source(graphicsTimer));

   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();
 
   al_start_timer(logicsTimer);
   
   al_start_timer(graphicsTimer);

	return true;
}