@0xe3148e3e52c75da3

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("ecal");

struct Field {
    enum NumericType {
        Float32 @0;
        Float64 @1;
        Int8 @2;
        Int16 @3;
        Int32 @4;
        Int64 @5;
        UInt8 @6;
        UInt16 @7;
        UInt32 @8;
        UInt64 @9;
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
