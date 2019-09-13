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

	private:

		/**
		 * @pre
		 * @post
		 * @brief
		 */
		void prettify_window_manager();

};

#endif // BATTLE_WINDOW_H_
