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

	private:
		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;

};
#endif // EXECUTIVE_H_
