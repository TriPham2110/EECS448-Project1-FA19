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

		int game_in_progress();

		void set_game_state(int state);

		void quit();

		BattleWindow* get_main_window();

	private:

		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;
		int gameState = 0;

};

#endif // EXECUTIVE_H_
n
