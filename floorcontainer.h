#ifndef FLOORCONTAINER_H
#define FLOORCONTAINER_H

#include <boost/unordered_map.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/functional/hash_fwd.hpp>
#include <dungeonEnums.h>

class floorContainer
{
public:
    typedef boost::fusion::vector3< int, int, int > vectorMapKey;

    template < typename vectorMapKey > // we can make this generic for any container [1]
    struct container_hash {
        std::size_t operator()( vectorMapKey const& c ) const {
            std::size_t hash;
            boost::hash_combine( hash, c.m0 );
            boost::hash_combine( hash, c.m1 );
            boost::hash_combine( hash, c.m2 );
            return hash;
        }
    };

    template < typename vectorMapKey > // we can make this generic for any container [1]
    struct container_equals {
        bool operator()( vectorMapKey const& vec1, vectorMapKey const& vec2 ) const {
            return ( vec1.m0 == vec2.m0 ) && ( vec1.m1 && vec2.m1 );
        }
    };

    typedef boost::unordered_map< vectorMapKey, dungeonenums::tileType, container_hash< vectorMapKey >, container_equals< vectorMapKey > > map;

    floorContainer();
    bool insertTile( boost::fusion::vector3< double, double, double > tileLocation, dungeonenums::tileType type );
    bool clear();
    bool deleteTile();
    map getMap();
    ~floorContainer();
private:
    dungeonenums::tileType tile;
    map floorMap;
};

#endif // FLOORCONTAINER_H
