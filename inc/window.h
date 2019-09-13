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

	protected:

		// Signal Handlers
		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void on_start_button_clicked();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void on_pause_button_clicked();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void on_exit_button_clicked();


		// Member Widgets
		Gtk::Button start_menu_button;
		Gtk::Button pause_menu_button;
		Gtk::Button exit_menu_button;

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
		void add_start_menu_button_decoration();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void add_pause_menu_button_decoration();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void add_exit_menu_button_decoration();

};

#endif // BATTLE_WINDOW_H_
