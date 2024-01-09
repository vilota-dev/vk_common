@0xe3148e3e52c75da3

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("ecal");

struct Field {
    enum NumericType {
        FLOAT32 @0;
        FLOAT64 @1;
        INT8 @2;
        INT16 @3;
        INT32 @4;
        INT64 @5;
        UINT8 @6;
        UINT16 @7;
        UINT32 @8;
        UINT64 @9;
    }
    name @0 :Text;
    offset @1 :UInt32;
    type @2 :NumericType;
}

struct PointCloud {
    header @0 :import "header.capnp".Header;
    pose @1 :import "odometry3d.capnp".Odometry3d;
    point_stride @2 :UInt32; # number of bytes between points in `points`
    fields @3 :List(Field); # fields in each point
    points @4 :Data;
}
