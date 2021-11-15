class Hero{
    public:
        Hero();

        void setSkin( char );
        void setHeroPosition( int, int );
        int getRowPosition();
        int getColumnPosition();

        int isMovingRight( char [][40], const int, const int );
        void goRight( char [][40], const int, const int );

        int isMovingLeft( char [][40], const int, const int );
        void goLeft( char [][40], const int, const int );

        int isMovingUp( char [][40], const int, const int );
        void goUp( char [][40], const int, const int );

        int isMovingDown( char [][40], const int, const int );
        void goDown( char [][40], const int, const int );

        void heroIn( char [][40], const int, const int );
        void heroOut( char [][40], const int, const int );
    protected:
        char skin;
        int rowPosition; 
        int columnPosition; 
};