//  Copyright (C) 2015-2019 Pierre-Olivier Latour <info@pol-online.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#import "GICommitViewController.h"
#import "GIViewController+Utilities.h"

@class GICommitRewriterViewController, GCHistoryCommit;

@protocol GICommitRewriterViewControllerDelegate <GICommitViewControllerDelegate, GCMergeConflictResolver>
- (void)commitRewriterViewControllerShouldFinish:(GICommitRewriterViewController*)controller withMessage:(NSString*)message;
- (void)commitRewriterViewControllerShouldCancel:(GICommitRewriterViewController*)controller;
@end

@interface GICommitRewriterViewController : GICommitViewController
@property(nonatomic, weak) id<GICommitRewriterViewControllerDelegate> delegate;
- (BOOL)startRewritingCommit:(GCHistoryCommit*)commit error:(NSError**)error;
- (BOOL)finishRewritingCommitWithMessage:(NSString*)message error:(NSError**)error;
- (BOOL)cancelRewritingCommit:(NSError**)error;
@end
