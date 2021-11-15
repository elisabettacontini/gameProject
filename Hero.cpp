#include "Hero.hpp"

Hero::Hero(){
    setHeroPosition( 18, 1 );
}

void Hero::setSkin( char skin ){
    this -> skin = skin;
}

void Hero::setHeroPosition( int row, int column ){
    rowPosition = row;
    columnPosition = column;
}

int Hero::getRowPosition(){
    return rowPosition;
}

int Hero::getColumnPosition(){
    return columnPosition;
}

int Hero::isMovingRight( char map[][40], const int r, const int c ){
    int x = rowPosition;
    int y = columnPosition;
    if( map[x][y++] == ' ' && map[x++][y++] == '=' ) return 0;
    else if( columnPosition == 39 ) return 1;
    else if( map[x][y++] == '=' ) return -1;
    //TODO : Aggiungere controlli su contatto nemico con nemici/bonus ( Necessitiamo di conoscore le skin dei bonus )
    return 1;
}

void Hero::goRight( char map[][40], const int r, const int c ){
    heroOut( map, 20, 40 );
    if( columnPosition == 39 ) setHeroPosition( 18, 1 );
    else columnPosition++;
    heroIn( map, 20, 40 );
}

int Hero::isMovingLeft( char map[][40], const int r, const int c ){
    int x = rowPosition;
    int y = columnPosition;
    if( map[x][y--] == ' ' && map[x++][y--] == '=' ) return 0;
    else if( columnPosition == 1 ) return 1;
    else if( map[x][y--] == '=' ) return -1;
    //TODO : Aggiungere controlli su contatto nemico con nemici/bonus ( Necessitiamo di conoscore le skin dei bonus )
    return 1;
}

void Hero::goLeft( char map[][40], const int r, const int c ){
    heroOut( map, 20, 40 );
    if( columnPosition == 1 ) setHeroPosition( 18, 39 );
    else columnPosition--;
    heroIn( map, 20, 40 );    
}

int Hero::isMovingUp( char map[][40], const int r, const int c ){
    int x = rowPosition;
    int y = columnPosition;
    if( map[x][y++] == '=' ) return 1;
    else return -1;
    //TODO : Aggiungere controlli su contatto nemico con nemici/bonus ( Necessitiamo di conoscore le skin dei bonus )
}

void Hero::goUp( char map[][40], const int r, const int c ){
    heroOut( map, 20, 40 );
    rowPosition--;
    columnPosition++;
    heroIn( map, 20, 40 );
}

int Hero::isMovingDown( char map[][40], const int r, const int c ){
    return -1;
    //TODO : Aggiungere controlli su contatto nemico con nemici/bonus ( Necessitiamo di conoscore le skin dei bonus )    
}

void Hero::goDown( char map[][40], const int r, const int c ){
    int x = rowPosition;
    int y = columnPosition;
    heroOut( map, 20, 40 );
    if( map[x++][y--] != '=' ){
        rowPosition++;
        columnPosition--;
    } else if( map[x++][y++] != '=' ){
        rowPosition++;
        columnPosition++;
    }
    heroIn( map, 20, 40 );
} 

// TODO: Valutare se tenere queste funzioni membro.
void Hero::heroIn( char map[][40], const int r, const int c ){
    map[rowPosition][columnPosition] = skin;
}

void Hero::heroOut( char map[][40], const int r, const int c ){
    map[rowPosition][columnPosition] = ' '; // empty space
}