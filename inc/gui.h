// -*- C++ -*-
/**
* @file   gui.h
* @date   14 September 2019
* @brief
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

		UserInterface();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~UserInterface();

		static FieldContainer* get_field_container();
		static MainMenu* get_main_menu();
		static ChangingPlayerWindow* get_changing_player_window();

	protected:
		FieldContainer* field_container;
		MainMenu* main_menu;
		ChangingPlayerWindow* changing_player_window;

	private:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_field_container();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_main_menu();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_changing_player_window();

};

#endif // GUI_H_
