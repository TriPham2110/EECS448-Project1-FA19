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
class Player;
class MainMenu;

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
		 * @brief Shows or hides player one's status and hit boards when necessary.
		 */
		void toggle_player_ones_board(int state);

		/**
		 * @brief Returns a pointer to the container for player one's boards.
		 * @return Player* pointer to container that holds play/view fields.
		 */
		static Player* get_player_one();

		/**
		 * @brief Returns a pointer to the container for player two's boards.
		 * @return Player* pointer to container that holds play/view fields.
		 */
		static Player* get_player_two();

		/**
		 * @brief Shows or hides player two's status and hit boards when necessary.
		 */
		void toggle_player_twos_board(int state);

	protected:
		Player* player_one;
		Player* player_two;
		MainMenu* main_menu;

	private:

		/**
		 * @brief Sets up the container that houses play/view fields.
		 * @details This is more syntactic sugar that lets us construct the
		 *          container that houses the playboards and then add it to
		 *          this container class without having to pollute the
		 *          constructor with a bunch of unreadable calls. It is
		 *          generally a good idea to abstract intent.
		 */
		void bootstrap_player_ones_container();

		/**
		 * @brief Sets up the container that houses play/view fields.
		 * @details This is more syntactic sugar that lets us construct the
		 *          container that houses the playboards and then add it to
		 *          this container class without having to pollute the
		 *          constructor with a bunch of unreadable calls. It is
		 *          generally a good idea to abstract intent.
		 */
		void bootstrap_player_twos_container();

		/**
		 * @brief Sets up the container that holds all the main menu buttons.
		 * @details This is more syntactic sugar that lets us construct the main
		 *          menu and add it to this container class without having to
		 *          pollute the constructor with a bunch of unreadable calls.
		 *          It is generally a good idea to abstract intent.
		 */
		void bootstrap_main_menu();

		int board_visible = 0;

};

#endif // GUI_H_
