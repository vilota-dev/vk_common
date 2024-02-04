@0x9d805819b50be7fe;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("vkc");

# Scalar r2 = p3dt[0] * p3dt[0] + p3dt[1] * p3dt[1];
# Scalar r = std::sqrt(r2);
# polar_azimuthal_angle[i][0] = std::atan2(r, p3dt[2]);
# polar_azimuthal_angle[i][1] = std::atan2(p3dt[0], p3dt[1]);

struct Flow2dTrack {
    seq @0 :Int32; # sequence in the past. 0 mean current prediction
    position @1 :import "vector2.capnp".Vector2f;
}

struct DistanceEstimation {

    enum DistanceEstimationMethod {
        singleFrameStereo @0;
        motionStereo @1;
    }

    method @0 :DistanceEstimationMethod;
    distance @1 :Float32; # in meters

}

struct Flow2d {

    enum DetectorMethod {
        fast @0;
        sparseStereo @1;
    }

    # shall remain simple for mono tracker?
    id @0 :UInt64; # the upper 32-bit encodes the hash of the camera/stereo, the lower 32-bit encodes the actual id
    position @1 :import "vector2.capnp".Vector2f; # should be in 0~1 range, respect to width and height
    radial @2 :Float32; # radial in radian, from the positive z-axis
    azimuth @3 :Float32; # azimuth in radian, from the positive y-axix, counter clockwise

    # TODO: add info about uncertainty, inferred from pixel. take account of rectification perhaps (more info from image)

    level @4 :UInt8; # mipmap level
    age @5 :UInt32;

    history @6 :List(Flow2dTrack); # first item would be predicted value, then historical
    detectorMethod @7 :DetectorMethod;
    # ditanceEstimations @8 :List(DistanceEstimation); 
}

# By design, the stereo optical flows would share the same id
struct HFOpticalFlowResult {

    header @0 :import "header.capnp".Header;
    streamName @1 :Text; # for debugging

    meanFlow @2 :List(Float32); # a ratio to the mean of height and width of the image, negative number means N.A.
    flowDensity @3 :List(Float32); # 9 numbers, centre, then clockwise from 0'o clock. sum indicate if we have at least 27 active tracking (3 average)
    flowData @4 :List(Flow2d); 

    image @5 :import "image.capnp".Image; # image data may not be populated, but intrinsic would
    
}

# we might run this at lower frequency
struct HFSparseStereoResult {

    header @0 :import "header.capnp".Header;
    streamName @1 :Text; # for debugging

    # new corners to be added, receiver to assign id
    fiducialCorners @2 :List(Flow2d); # id likely to be the corner id, enhanced by grid;
    matchedCorners @3 :List(Flow2d); # from motion stereo or actual stereo; the id can be existing, or requesting a new one given by the sender
    filteredCorners @4 :List(UInt64); # to remove from the tracking
    # updatedCorners @5 :List(Flow2d)

}