@0xd569317e0d67b155;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("vkc");

# https://www.ros.org/reps/rep-0103.html where NWU is defined for body frame
# https://www.ros.org/reps/rep-0105.html where ENU is defined for global frame



struct Odometry3d {

    enum BodyFrame {
        nwu @0;
        ned @1;
    }

    enum ReferenceFrame {
        enu @0; # typically with global reference, map frame of ROS
        nwu @1; # typically with local reference, odom frame of ROS
        ned @2; # typically with MAV
    }

    enum VelocityFrame {
        none @0; # not implemented
        body @1; # body frame velocity
        reference @2; # refernece frame velocity
    }

    header @0 :import "header.capnp".Header;
    bodyFrame @1 :BodyFrame;
    referenceFrame @2 :ReferenceFrame;
    velocityFrame @3 :VelocityFrame;

    pose @4 :import "se3.capnp".Se3;
    poseCovariance @5 :List(Float32); # either 21 or 36 numbers of float

    twist @6 :import "twist3.capnp".Twist3;
    twistCovariance @7 :List(Float32); # either 21 or 36 numbers of float

    resetCounter @8 :UInt32;

    metricVisionFailureLikelihood @9 :Float32; # 0 means vision functioning, 1 means imu only
    metricInertialFailureLikelihood @10 :Float32; # 0 means imu function, 1 means imu bias estimation is bad
    estimatedFailureModeDrift @11 :Float32; # additional drift due to vision failure

}