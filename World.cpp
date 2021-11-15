#include "World.hpp"

World::World() {
    M.startMenu();
    H.setSkin( M.getPlayerSkin() );
    D.setName(M.getPlayerName());
}

void World::createAndPrintFirstLevel(){
    counterNode = 0;
    D.riseLevelNumber();
    tmp = new Map;
    addEmptySpace(tmp->matrix);
    leftWall(tmp->matrix);
    topDownWall(tmp->matrix);
    tmp -> prec = p;
    q = tmp;
    p = tmp;	
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;  
    Platform P;
    Bonus B = Bonus (D.getDifficulty());
    B.getChoice(P.PatternChoice( tmp -> matrix, X, Y ), tmp -> matrix, X, Y);
    H.heroIn( tmp -> matrix, X, Y );
    D.printData();
    printMap(tmp ->matrix);
}

void World::addNode() {
    counterNode++;
    D.riseLevelNumber();
    tmp = new Map;
    addEmptySpace(tmp->matrix);
    topDownWall(tmp->matrix);
    tmp -> prec = p;
    p->next = tmp;
    p = tmp;
    p->next = NULL;
    L.tail = p;
    L.ptr = L.tail;
    L.head = q;
}

void World::changeNode( bool direction ) {
}

void World::addEmptySpace(char m[][40]) {
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 40; j++ ){
            m[i][j] = ' ';
        }
    }
}

void World::printMap(char m[][40]) {
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
    for( int i = 0; i < 20; i++ ){
        for( int j = 0; j < 40; j++ ){
            cout << m[i][j];
        }
        cout<<endl;
    }
}

void World::leftWall(char m[][40]) {
    for( int i = 0; i < 19; i++ )
        m[i][0] ='|';
}

void World::topDownWall(char m[][40]) {
    for( int i = 0; i < 40; i++){
        m[0][i] = '=';
        m[19][i] = '=';
    }
}

void World::updateData() {
}

void World::gameover() {
}

void World::startGame() {
    system("cls");
    createAndPrintFirstLevel();
    int key;
    while( (key = _getch()) != 'x' && D.getLifePoints() > 0 ){
        switch( key ){
            case 'A':
            case 'a':
                userPressA();
                break; 
            case 'D':
            case 'd': 
                userPressD();
                break;
            case 'W':
            case 'w':
                userPressW();
                break;
            case 'S':
            case 's':
                userPressS();
                break; 
            default: 
                break;
        }
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE), {0,0});
    printMap( tmp -> matrix );
    }
}

void World::userPressA(){
    switch( H.isMovingLeft( tmp -> matrix, X, Y ) ){
        case 0:
            H.goLeft( tmp -> matrix, X, Y );
            break;
        case 1:
            if( counterNode != 1 ){
                changeNode( 0 );
                H.goLeft( tmp -> matrix, X, Y );
            }
            break;
        case 2:
            // TODO
            break;
        case 3:
            // TODO
            break;
        default:
            break;
    }
}

void World::userPressD(){
    switch( H.isMovingRight( tmp -> matrix, X, Y ) ){
        case 0:
            H.goRight( tmp -> matrix, X, Y );
            break;
        case 1:
            if( counterNode == D.getLevelNumber() ) addNode();
            else changeNode( 1 );
            H.goRight( tmp -> matrix, X, Y );
            break;
        case 2:
            // TODO
            break;
        case 3:
            // TODO
            break;
        default:
            break;
    }
}

void World::userPressW(){
    switch( H.isMovingUp( tmp -> matrix, X, Y ) ){
        case 1:
            H.goUp( tmp -> matrix, X, Y );
            break;
        case 2:
            // TODO
            break;
        case 3:
            // TODO
            break;
        default:
            break;
    }
}

void World::userPressS(){
    switch( H.isMovingDown( tmp -> matrix, X, Y ) ){
        case 0:
            H.goDown( tmp -> matrix, X, Y );
            break;
        case 1:
            // TODO
            break;
        case 2:
            // TODO
        default:
            break;
    }
}