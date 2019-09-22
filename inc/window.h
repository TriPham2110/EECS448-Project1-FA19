// -*- C++ -*-
/**
 * @file   window.h
 * @date   06 September 2019
 * @brief  Container for main menu and playing field widgets.
 */

#ifndef BATTLE_WINDOW_H
#define BATTLE_WINDOW_H

#include <gtkmm/window.h>

// Forward Declarations
class UserInterface;

class BattleWindow : public Gtk::Window {

	public:

		/**
		 * @pre The executive object must be created and the application must run.
		 * @post Creates the window which will serve as the container for all other GTK widgets.
		 * @brief Window constructor.
		 */
		BattleWindow();

		/**
		 * @brief Window destructor.
		 */
		virtual ~BattleWindow();

		/**
		 * @brief Returns a pointer to the user interface container.
		 * @return UserInterface* A pointer to the container that houses the main menu and playing fields.
		 */
		UserInterface* get_user_interface();

	protected:
		UserInterface* user_interface;

	private:

		/**
		 * @brief Sets up the aesthetics of the window.
		 * @details This is syntactic sugar that prevents you from having to
		 *          pollute the constructor with extraneous calls to GTK member
		 *          functions. Any way you want to set the window up as it is
		 *          being constructed, throw in here.
		 */
		void prettify_window_manager();

		/**
		 * @brief Adds necessary containers to the window.
		 * @details Again, this is syntactic sugar that prevents you from having
		 *          to pollute the constructor with calls to other GTK member
		 *          functions and objects. If there is something you want to add
		 *          to the window, put it here.
		 */
		void bootstrap_user_interface();

};

#endif // BATTLE_WINDOW_H_
