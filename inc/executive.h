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
		Executive();
		Executive(int argc, char* argv[]);
		~Executive();
		int run();

	private:
		Glib::RefPtr<Gtk::Application> app;
		BattleWindow* main_window;

};
#endif // EXECUTIVE_H_
