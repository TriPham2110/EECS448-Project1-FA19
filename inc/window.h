// -*- C++ -*-
/**
 * @file   window.h
 * @date   06 September 2019
 * @brief  TODO: Brief description
 */

#ifndef BATTLE_WINDOW_H
#define BATTLE_WINDOW_H

#include <gtkmm/window.h>

// Forward Declarations
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

		static UserInterface* get_user_interface();

	protected:
		UserInterface* user_interface;

	private:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void prettify_window_manager();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_user_interface();

};

#endif // BATTLE_WINDOW_H_
