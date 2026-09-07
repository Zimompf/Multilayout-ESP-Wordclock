#pragma once

#include "DE10x11.schwaebisch.hpp"

/*
 *           Layout Front
 *                COL
 *       X 9 8 7 6 5 4 3 2 1 0
 * ROW + - - - - - - - - - - -
 *  0  | E S K I S C H B E N I
 *  1  | D R E I V I E R T L A
 *  2  | Z E H N B I E F Ü N F
 *  3  | N A C H M I R I V O R
 *  4  | H A L B X F Ü N F E I
 *  5  | O I S E C H S E L F E
 *  6  | Z W O I E A C H T E D
 *  7  | D R E I E Z W Ö L F E
 *  8  | Z E H N E U N E U H L
 *  9  | S I E B N E V I E R E
 *
 * Personalized variant of the Swabian layout: the unused "FUNK" and "GERT"
 * filler words are replaced by the names "BENI" and "MIRI", which can be
 * switched on/off individually with their own color (e.g. via Home
 * Assistant), independent from the time-telling words.
 */

class De10x11SchwaebischBeniMiri_t : public De10x11schwaebisch_t {
public:
    //------------------------------------------------------------------------------

    virtual bool hasSpecialWordsBeniMiri() override { return true; }

    //------------------------------------------------------------------------------

    void show(FrontWord word) override {
        switch (word) {

        case FrontWord::beni:
            setFrontMatrixWord(0, 0, 3);
            break;

        case FrontWord::miri:
            setFrontMatrixWord(3, 3, 6);
            break;

        default:
            De10x11schwaebisch_t::show(word);
            break;
        };
    };
};

De10x11SchwaebischBeniMiri_t _de10x11SchwaebischBeniMiri;
