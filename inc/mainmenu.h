// -*- C++ -*-
/**
* @file   gui.h
* @date   13 September 2019
* @brief
*/

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>

class MainMenu : public Gtk::Box {

	public:

		MainMenu();

		virtual ~MainMenu();

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
		void add_start_menu_button_decoration();
		void add_pause_menu_button_decoration();
		void add_exit_menu_button_decoration();

};
#endif // GUI_H_
