//
//  KFBroadcastViewController.h
//  Kickflip
//
//  Created by Christopher Ballinger on 1/16/14.
//  Copyright (c) 2014 Christopher Ballinger. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "KFRecorder.h"
#import "KFRecordButton.h"

/**
 *  Block executed when stream is ready.
 *
 *  @param streamURL URL to the streamable m3u8
 *  @see presentBroadcasterFromViewController:ready:completion:
 */
typedef void (^KFBroadcastReadyBlock)(id<BroadcastStream> stream);

/**
 *  Block executed when completed live broadcast
 *
 *  @param success Whether or not broadcast was successful
 *  @param error   Any error that occurred
 *  @see presentBroadcasterFromViewController:ready:completion:
 */
typedef void (^KFBroadcastCompletionBlock)(BOOL success, NSError* error);

/**
 *  This is the main broadcast user interface that presents a start/stop button
 *  and provides the user with the ability to share a link to the stream
 *  when it has buffered enough segments.
 *
 *  You can also use the Kickflip class to show this view from any UIViewController.
 */
@interface KFBroadcastViewController : UIViewController <KFRecorderDelegate>

@property (nonatomic, copy) KFBroadcastReadyBlock readyBlock;
@property (nonatomic, copy) KFBroadcastCompletionBlock completionBlock;

@property (strong, nonatomic) UIView *cameraView;
@property (nonatomic, strong) UIButton *shareButton;
@property (nonatomic, strong) KFRecordButton *recordButton;
@property (nonatomic, strong) UIImageView *liveBanner;

@property (nonatomic, strong) KFRecorder *recorder;
@property (nonatomic, strong) NSURL *shareURL;

@property (nonatomic, strong) UILabel *rotationLabel;
@property (nonatomic, strong) UIImageView *rotationImageView;
@property (nonatomic, strong) UIButton *cancelButton;

- (instancetype) initWithAPIClient:(id<BroadcastAPIClient>)apiClient;

@end
