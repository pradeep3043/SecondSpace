var app= angular.module("pradeepApp",["ui.router"])

app.config(["$stateProvider","$urlRouterProvider",function($stateProvider,$urlRouterProvider){
   $urlRouterProvider.otherwise("/");	
   $stateProvider
   .state("iot",{
   	  url:"/",
   	  templateUrl:"/js/template/app.html",
   	  controller:function($scope,$state){
   	  	$scope.list= [{name:"Bulb",id:"bulp",icon:"light"},{name:"Ketle",id:"ketle"},{name:"Fan",id:"fan"},{name:"Fridge",id:"fridge"},{name:"Door",id:"door"}];
   	  }
   })
   .state("bulb",{
   	  url:"/bulb",
   	  templateUrl:"/js/template/iot-item.html",
   	  controller:function($scope,$http){
   	  	   $scope.bulb={};
           $scope.onAndOff =function(data){
              data.isOn = !data.isOn;
           	  $http.post("/handler",data)
           	    .success(function(data){
           	    	console.log(data);
           	    });
           } 
   	  }
   })
}]);