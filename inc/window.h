// -*- C++ -*-
/**
 * @file   window.h
 * @date   06 September 2019
 * @brief
 */

#ifndef BATTLE_WINDOW_H
#define BATTLE_WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>

class BattleWindow : public Gtk::Window {

	public:

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		BattleWindow();

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~BattleWindow();

	protected:

		// Signal Handlers
		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void on_start_button_clicked();

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void on_pause_button_clicked();

		/**
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

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void prettify_window_manager();

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void add_start_menu_button_decoration();

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void add_pause_menu_button_decoration();

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void add_exit_menu_button_decoration();

};

#endif // BATTLE_WINDOW_H_
