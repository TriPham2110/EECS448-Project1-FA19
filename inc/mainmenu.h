// -*- C++ -*-
/**
 * @file   gui.h
 * @date   13 September 2019
 * @brief  Container class that houses a GTK Box and several buttons, to serve as
 *         the menu.
 */

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/comboboxtext.h>
#include <gtk/gtk.h>

class MainMenu : public Gtk::Box {

	public:

		/**
		 * @brief Menu constructor.
		 */
		MainMenu();

		/**
		 * @brief Menu destructor.
		 */
		virtual ~MainMenu();

	protected:

		// Signal Handlers
		/**
		 * @pre   Main menu must be created.
		 * @post  Start the game. If a game is in progress, ask other player for
		 *        confirmation. If both agree, restart game.
		 * @brief Singal handler for what should happen when the start button is
		 *        clicked.
		 */
		void on_start_button_clicked();

		/**
		 * @pre   Main menu must be created.
		 * @post  If paused, resume. If not paused, pause. Sets state with
		 *        callback to Executive object.
		 * @brief Singal handler for what should happen when the pause button is
		 *        clicked.
		 */


		/**
		 * @pre   Main menu must be created.
		 * @post  Program exits, though not cleanly (no destructors are called.)
		 * @brief Singal handler for what should happen when the exit button is
		 *        clicked.
		 */
		void on_exit_button_clicked();

		/**
		 * @pre   Main menu must be created.
		 * @post  If player confirms, hand control to other player; reflect
		 *        change in executive object.
		 * @brief Singal handler for what should happen when the end turn button
		 *        is clicked.
		 */
		void on_start_turn_button_clicked();

		/**
		 * @pre   Main menu must be created.
		 * @post  If player confirms, hand control to other player; reflect
		 *        change in executive object.
		 * @brief Singal handler for what should happen when the end turn button
		 *        is clicked.
		 */
		void on_end_turn_button_clicked();

		/**
		 * @pre   Main menu must be created.
		 * @post  Sets number of ships next game should start with in executive
		 *        object.
		 * @brief Singal handler for what should happen when the player chooses
		 *        some number of ships to play with.
		 */
		int get_result_from_ship_dropdown();

		// Member Widgets
		Gtk::ComboBoxText num_ships_dropdown;
		Gtk::Button start_menu_button;

		//GtkWidget *buttonbox = gtk_vbutton_box_new();
		//GtkWidget *button;

		Gtk::Button exit_menu_button;
		Gtk::Button end_turn_menu_button;
		Gtk::Button start_turn_menu_button;

	private:

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		void add_start_menu_button_decoration();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */


		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		void add_exit_menu_button_decoration();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		void add_start_turn_menu_button_decoration();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		void add_end_turn_menu_button_decoration();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		void add_num_ships_dropdown_decoration();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		int confirm_new_game_popup();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		int confirm_switch_players_popup();

		/**
		 * @brief Syntactic sugar that lets us avoid polluting other functions
		 *        with calls that do not have anything to do with their intent.
		 */
		int confirm_exit_popup();

};
#endif // GUI_H_
