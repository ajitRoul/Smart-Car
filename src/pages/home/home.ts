import { Component } from '@angular/core';
// import { NavController } from 'ionic-angular';
import { AngularFireDatabase, AngularFireObject } from '@angular/fire/database';
import { Observable } from 'rxjs';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  itemRef: AngularFireObject<any>;
  item: Observable<any>;
  
  constructor(db: AngularFireDatabase) {
    this.itemRef = db.object('user');
    this.item = this.itemRef.valueChanges();
  }

  carControl(type){
   if(type=="forward"){
    this.itemRef.set(2);
   }else if(type=="back"){
    this.itemRef.set(1);
   }else{
    this.itemRef.set(0);
   }
  }


}
