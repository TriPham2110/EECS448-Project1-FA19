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

// Executive
class Executive {

	public:
		Executive();
		Executive(int argc, char* argv[]);
		~Executive();
		int run();

	private:

};
#endif // EXECUTIVE_H_
