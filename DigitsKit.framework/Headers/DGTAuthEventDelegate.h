//
//  DGTAuthEventDelegate.h
//  DigitsKit
//
//  Copyright © 2016 Twitter Inc. All rights reserved.
//

@class DGTAuthEventDetails;

@protocol DGTAuthEventDelegate <NSObject>

@optional

/**
 *  Called when the Digits authentication flow starts.
 */
- (void)digitsAuthenticationDidBegin:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called as soon as the phone number screen appears.
 */
- (void)digitsPhoneNumberEntryScreenVisited:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called each time a phone number is submitted to Digits.
 */
- (void)digitsPhoneNumberSubmitted:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called when the phone number is accepted by Digits. This is an indication that we were able to successfully send a confirmation code to the end-user.
 */
- (void)digitsPhoneNumberSubmissionDidSucceed:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called as soon as the confirmation screen appears.
 */
- (void)digitsConfirmationCodeEntryScreenVisited:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called each time a confirmation code is submitted to Digits.
 */
- (void)digitsConfirmationCodeSubmitted:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called as soon as the phone number screen appears.
 */
- (void)digitsAuthenticationDidComplete:(DGTAuthEventDetails *)authEventDetails;

/**
 *  Called if the -[Digits logout] method is invoked.
 */
- (void)digitsLogout:(DGTAuthEventDetails *)authEventDetails;

@end
