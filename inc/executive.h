// -*- C++ -*-
/**
 * @file   executive.h
 * @date   06 September 2019
 * @brief  Bootstraps the GTK+ window in which our program will run.
 */

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <glibmm/refptr.h>
#include <gtkmm/application.h>

// Forward Declarations
class BattleWindow;

// Executive
class Executive {

	public:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		Executive();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		Executive(int argc, char* argv[]);

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		~Executive();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		int run();

		static Executive* get_executive_object();

		int get_game_in_progress_state();

		void set_game_in_progress_state(int state);

		int get_game_paused_state();

		void set_game_paused_state(int state);

		int which_player_is_up();

		void set_which_player(int player);

		void quit();

		BattleWindow* get_main_window();

	private:

		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;
		int gameInProgressState = 0;
		int whichPlayer = 0;
		int gamePausedState = 0;
};

#endif // EXECUTIVE_H_
