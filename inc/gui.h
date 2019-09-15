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
class PlayingField;
class MainMenu;

class UserInterface : public Gtk::Box {

	public:

		UserInterface();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		virtual ~UserInterface();

	protected:
		PlayingField* playing_field;
		MainMenu* main_menu;

	private:

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_playing_field();

		/** TODO: Add documentation
		 * @pre
		 * @post
		 * @brief
		 */
		void bootstrap_main_menu();

};

#endif // GUI_H_
