// -*- C++ -*-
/**
* @file   gui.h
* @date   14 September 2019
* @brief  Container for the GUI: main menu bar and playfield
*/

#ifndef GUI_H
#define GUI_H

#include <gtkmm/box.h>

// Forward Declaration of Submodules
class FieldContainer;
class MainMenu;
class ChangingPlayerWindow;

class UserInterface : public Gtk::Box {

	public:

		/**
		 * @brief Constructor for interface container.
		 * @details A lot of GTK elements only allow one widget to be added, so
		 *          it was necessary to put a container that could house multiple
		 *          widgets into the window, which could technically only contain
		 *          one itself (this one).
		 */
		UserInterface();

		/**
		 * @brief User interface destructor. Deletes main menu and playing field.
		 */
		virtual ~UserInterface();

		/**
		 * @brief Returns a pointer to the field container.
		 * @return FieldContainer* pointer to container that holds play/view fields.
		 */
		static FieldContainer* get_field_container();

		/**
		 * @brief Returns a pointer to the main menu.
		 * @return MainMenu* pointer to main menu container.
		 */
		static MainMenu* get_main_menu();

		/**
		 * @brief TODO What is this
		 */
		static ChangingPlayerWindow* get_changing_player_window();

	protected:
		FieldContainer* field_container;
		MainMenu* main_menu;
		ChangingPlayerWindow* changing_player_window;

	private:

		/**
		 * @brief Sets up the container that houses play/view fields.
		 * @details This is more syntactic sugar that lets us construct the
		 *          container that houses the playboards and then add it to
		 *          this container class without having to pollute the
		 *          constructor with a bunch of unreadable calls. It is
		 *          generally a good idea to abstract intent.
		 */
		void bootstrap_field_container();

		/**
		 * @brief Sets up the container that holds all the main menu buttons.
		 * @details This is more syntactic sugar that lets us construct the main
		 *          menu and add it to this container class without having to
		 *          pollute the constructor with a bunch of unreadable calls.
		 *          It is generally a good idea to abstract intent.
		 */
		void bootstrap_main_menu();

		/**
		 * @brief TODO What is this
		 * @details TODO What is this
		 */
		void bootstrap_changing_player_window();

};

#endif // GUI_H_
