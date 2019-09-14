// -*- C++ -*-
/**
 * @file   window.h
 * @date   06 September 2019
 * @brief  TODO: Brief description
 */

#ifndef BATTLE_WINDOW_H
#define BATTLE_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

// Forward Declaration of Game Field & Menu Container
class UserInterface;

class BattleWindow : public Gtk::Window {

	public:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		BattleWindow();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~BattleWindow();

	private:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void prettify_window_manager();

		UserInterface* user_interface;
};

#endif // BATTLE_WINDOW_H_
