//
//  ViewController.swift
//  FabricSample
//
//  Created by Yusuke Yasuo on 2016/06/20.
//  Copyright © 2016年 redish.inc. All rights reserved.
//

import UIKit
import DigitsKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        let authButton = DGTAuthenticateButton(authenticationCompletion: { (session: DGTSession?, error: NSError?) in
            if (session != nil) {
                // TODO: associate the session userID with your user model
                let message = "Phone number: \(session!.phoneNumber)"
                NSLog("User Id: \(session!.userID)")
                let alertController = UIAlertController(title: "You are logged in!", message: message, preferredStyle: .Alert)
                alertController.addAction(UIAlertAction(title: "Cancel", style: .Cancel, handler: .None))
                self.presentViewController(alertController, animated: true, completion: .None)
                let digits = Digits.sharedInstance()
                let oauthSigning = DGTOAuthSigning(authConfig:digits.authConfig, authSession:digits.session())
                let authHeaders: NSDictionary = oauthSigning.OAuthEchoHeadersToVerifyCredentials()
                print(authHeaders.objectForKey("X-Auth-Service-Provider"))
                print(authHeaders.objectForKey("X-Verify-Credentials-Authorization"))
            } else {
                NSLog("Authentication error: %@", error!.localizedDescription)
            }
        })
        authButton.center = self.view.center
        self.view.addSubview(authButton)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

