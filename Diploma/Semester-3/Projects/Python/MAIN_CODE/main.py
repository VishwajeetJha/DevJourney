"""Work started on 16-10-2023 10:51 IST

This program is going to be a simple Bus Management System implementation 
based on my code in C++ (ideally) of a Bus Management System but WITH GUI and in Python.

--------------------------------------------------------------------------------
Work Done so far:-
    16/10/23
1. Added functions for bus add, remove, 
    seat reserve, and display, of both --> basic code
2. The object blueprints(class) required for the
    bus mgmt related objects --> basic code

    17/10/23
3. Implemented gui partially 

    19/10/23
4. Fixed properly main menu not calling of functions
5. GUI FIX -- properly working entry of gui
6. Can't keep track of everything :v
7. Fixed stuff here and there
    
    27/10/23
8. Duplicacy Prevention in bus add
9. 

--------------------------------------------------------------------------------
Notes:-
18/10/23:-
1. none, just keep going!

21/10/23:-
1. code me basic gui implement ho gaya hai, anytime soon we shall start 
    implementing file system and also try to reduce code.
2. right now important thing is to make the windows look good,
    currently they look boring :vvvv

26/10/23:-
1. Currency

--------------------------------------------------------------------------------
To-Do:-
1. Uncomment the "Cancel Reservation" codes and 
    reimplement them with GUI
2. Beautify the windows
3. Implement file saving like in C++ code, 
    comma-seperated values(CSVs) to save bus and
    seats' reservations information
4. fix availableSeats 
5. make-do so that when you enter BusNumber in Reserve Seat the window updates instead of expanding
6. Improve GUI looks
7. Duplicacy Prevention in Seat Reserve

Todo:-
---------->Fix reserve seat and delete seat wrong value insertion!

--------------------------------------------------------------------------------
PRIORITY JOB: Implement GUI -----> DONE 20/10/23
Next PRIORITY JOB: Implement FileSystem
PRIORITY JOB: Reserve Seat not working properly

COs Covered:-
a) Develop programs to solve the given simple computational problems.
b) Apply control flow structures to solve the given problems.
c) Implement data structures lists, tuples, sets and dictionaries to solve the given 
problems.
d) Apply modular programming approach to solve given problems using user-defined 
functions.
e) Perform string manipulation and file operations to solve a given problem

"""

import tkinter as tk #for gui
import os

# bus class to store bus information
class Bus:
    def __init__(self, busNumber, source, destination, totalSeats): #constructor
        self.busNumber = busNumber #self = "this" pointer just to understand
        self.source = source
        self.destination = destination
        self.totalSeats = totalSeats
        self.availableSeats = totalSeats

# reservation class for seats and all
class Reservation:
    def __init__(self, busNumber, passengerName, seatNumber):#constructor
        self.busNumber = busNumber
        self.passengerName = passengerName
        self.seatNumber = seatNumber

#List of bus objects
buses = []
#List of bus reservation objects
reservations = []

#isalpha wasn't working how I wanted it to, so I made my own thing :3
def is_completely_alpha(input_string):
    return input_string.isalpha() and all(char.isalpha() or char.isspace() for char in input_string)


#Function to add bus information, adds new bus object to "buses" list
def addBus(buses):
    abus=tk.Tk()
    abus.title("Add a Bus")
    height = min(abus.winfo_reqheight(), 906)
    abus.minsize(360, height)
    abus.iconbitmap("bus.ico")

    def ex():
        abus.destroy()

    label = tk.Label(abus, text="Enter Bus Information",font=(16))
    label.pack()
    label = tk.Label(abus, text="Enter Bus Number:")
    label.pack()
    busNumber = tk.Entry(abus) #input("Enter bus number: ")
    busNumber.pack()
    label = tk.Label(abus, text="Enter Source:")
    label.pack()
    source = tk.Entry(abus) #input("Enter source: ")
    source.pack()
    label = tk.Label(abus, text="Enter Destination:")
    label.pack()
    destination = tk.Entry(abus) #input("Enter destination: ")
    destination.pack()
    label = tk.Label(abus, text="Enter Total Seats:")
    label.pack()
    totalSeats = tk.Entry(abus) #int(input("Enter total seats: "))
    totalSeats.pack()
    def submit_bus():
        if not(busNumber.get().isdigit() and totalSeats.get().isdigit()) or not(source.get().isalpha() and destination.get().isalpha()):
            err = tk.Tk()
            err.geometry("210x50")
            err.iconbitmap("err.ico")
            err.title("Error!")
            label = tk.Label(err, text="Please enter proper values..!")
            label.pack()
            okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
            okB.pack()

        else:
            # Get the values from the Entry widgets
            bus_num = busNumber.get()
            src = source.get()
            dest = destination.get()
            seats = int(totalSeats.get())

            """Duplicacy Prevention"""
            dupFound = False
            for bus in buses:
                if bus.busNumber == busNumber.get():
                    dupFound = True
                    err = tk.Tk()
                    err.geometry("210x50")
                    err.iconbitmap("err.ico")
                    err.title("Error!")
                    label = tk.Label(err, text=f"Bus Number:{busNumber.get()} already exists!")
                    label.pack()
                    okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
                    okB.pack()
                    break
            
            #THOROUGHLY ENSURING BUS DOESN'T EXIST AND THEN ADDING
            if not dupFound and busNumber.get() not in [bus.busNumber for bus in buses]:
                # Create a Bus object and append it to the buses list
                buses.append(Bus(bus_num, src, dest, seats))
                if not dupFound and busNumber.get() in [bus.busNumber for bus in buses]:
                    scc = tk.Tk()
                    scc.geometry("230x60")
                    scc.iconbitmap("scc.ico")
                    scc.title("Success!")
                    label = tk.Label(scc, text="Bus successfully added!")
                    label.pack()
                    def desext():
                        scc.after(300, scc.destroy())
                        try:
                            if abus.winfo_exists():
                                abus.after(600, abus.destroy())
                        except tk.TclError:
                            #stupid tkinter doesn't YET have the ability to see whether one window
                            #existed early or not. It checks in present only, there I need this
                            #to ignore the error raised because a stupid window doesn't exist
                            #and I want to close it
                            pass

                    okB = tk.Button(scc, text="Ok", command=lambda: desext())
                    okB.pack()

    submit_button = tk.Button(abus, text="Submit", command=submit_bus)
    submit_button.pack(pady=2)
    exB = tk.Button(abus,text="Exit",command=ex)
    exB.pack(pady=2)

#Function to remove a bus, basically removes the bus object from "buses" list
def removeBus(buses,reservations):
    rbus=tk.Tk()
    rbus.title("Remove Bus")
    height = min(rbus.winfo_reqheight(), 906)
    rbus.minsize(360, height)
    rbus.iconbitmap("bus.ico")

    def ex():
        rbus.destroy()
    
    def remove_bus():
        if not(busNumber.get().isdigit()):
            err = tk.Tk()
            err.geometry("210x50")
            err.iconbitmap("err.ico")
            err.title("Error!")
            label = tk.Label(err, text="Please enter proper value..!")
            label.pack()
            okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
            okB.pack()
        else:
            busFound = False
            resvFound = False
            for bus in buses:
                if bus.busNumber == busNumber.get():
                    busFound = True
                    for resv in reservations:
                        if resv.busNumber == bus.busNumber:
                            resvFound = True
                            reservations.remove(resv)
                    buses.remove(bus)
                    saveBus(buses)
                    saveRes(reservations)
            if not busFound:
                label = tk.Label(rbus, text="Bus not found!",font=(12))
                label.pack()
                rbus.after(2000, label.pack_forget)
            elif busFound and busNumber.get() not in [bus.busNumber for bus in buses]:
                def desext():
                    scc.after(300, scc.destroy())
                    try:
                        if rbus.winfo_exists():
                            rbus.after(600, rbus.destroy())
                    except tk.TclError:
                        pass
                if busFound and resvFound:
                    scc = tk.Tk()
                    width = min(scc.winfo_reqwidth(), 420)
                    scc.minsize(width, 60)
                    scc.iconbitmap("scc.ico")
                    scc.title("Success!")
                    label = tk.Label(scc, text="Bus successfully removed along with reservations!")
                    label.pack(padx=6)
                elif busFound and not resvFound:
                    scc = tk.Tk()
                    scc.geometry("260x50")
                    scc.iconbitmap("scc.ico")
                    scc.title("Success!")
                    label = tk.Label(scc, text="Bus successfully removed!")
                    label.pack()
                okB = tk.Button(scc, text="Ok", command=lambda: desext())
                okB.pack()

    if not buses:
        label = tk.Label(rbus, text="No Bus Currently in System!", font=(12))
        label.pack()
    else:
        label = tk.Label(rbus, text="Available Buses to Remove:",font=(10))
        label.pack()
        
        for bus in buses:
            binfo = tk.Label(rbus, text=f"Bus Number: {bus.busNumber}\nSource: {bus.source}\nDestination: {bus.destination}\nAvailable Seats: {bus.availableSeats}")
            binfo.pack()

        label = tk.Label(rbus, text="Enter bus number to remove:")
        label.pack()
        busNumber = tk.Entry(rbus)
        busNumber.pack()

        remove_button = tk.Button(rbus, text="Remove", command=remove_bus)
        remove_button.pack()

    exB = tk.Button(rbus,text="Exit",command=ex)
    exB.pack(pady=2)

def cancelReserve(buses,reservations):
    rres = tk.Tk()
    rres.title("Cancel Reservation")
    height = min(rres.winfo_reqheight(), 906)
    rres.minsize(360, height)
    rres.iconbitmap("bus.ico")
    def ex():
        rres.destroy()
    
    def clear_widgets():
        for widget in rres.winfo_children():
            widget.destroy()
    
    def cancel_res(seatNo,busnum):
        if not(seatNo.isdigit() and (busnum.isdigit())):
            err = tk.Tk()
            err.geometry("210x50")
            err.iconbitmap("err.ico")
            err.title("Error!")
            label = tk.Label(err, text="Please enter proper values..!")
            label.pack()
            okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
            okB.pack()
        else:
            busFound = False
            for res in reservations:
                if res.seatNumber == seatNo:
                    busFound = True
                    reservations.remove(res)
                    for bus in buses:
                        if bus.busNumber == busnum:
                            bus.availableSeats+=1
                            saveBus(buses)
                    saveRes(reservations)
            if not busFound:
                label = tk.Label(rres, text="Reservation not found!\nPlease check values put and try again..")
                label.pack()
                rres.after(3400, label.pack_forget)
            elif busFound:
                scc = tk.Tk()
                scc.geometry("230x80")
                scc.iconbitmap("scc.ico")
                scc.title("Success!")
                label = tk.Label(scc, text="Bus reservation successfully removed!")
                label.pack()
                def desext():
                    scc.after(300, scc.destroy())
                    try:
                        if rres.winfo_exists():
                            rres.after(600, rres.destroy())
                    except tk.TclError:
                        pass
                okB = tk.Button(scc, text="Ok", command=lambda: desext())
                okB.pack()

    if not buses:
        label = tk.Label(rres, text="No Bus Currently in System!", font=(12))
        label.pack()
    else:
        for bus in buses:
            binfo = tk.Label(rres, text=f"Bus Number: {bus.busNumber}\nSource: {bus.source}\nDestination: {bus.destination}\nAvailable Seats: {bus.availableSeats}\n")
            binfo.pack()
        
        bnum = tk.Label(rres, text="Enter Bus Number for reservations: ")
        bnum.pack()

        bus_num = tk.Entry(rres)
        bus_num.pack()

        def canRes():
            if not(bus_num.get().isdigit()):
                err = tk.Tk()
                err.geometry("210x50")
                err.iconbitmap("err.ico")
                err.title("Error!")
                label = tk.Label(err, text="Please enter proper values..!")
                label.pack()
                okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
                okB.pack()
            else:
                busnum = bus_num.get()
                clear_widgets()
                busFound=False
                for res in reservations:
                    if res.busNumber == busnum:
                        busFound=True
                        break

                if not busFound:
                    label = tk.Label(rres, text="No Reservations Currently in this bus!", font=(12))
                    label.pack()

                    exB = tk.Button(rres,text="Exit",command=ex)
                    exB.pack(pady=2)
                else:
                    label = tk.Label(rres, text="Available Reservations to Remove:",font=(6))
                    label.pack()

                    for resv in reservations:
                        if resv.busNumber == busnum:
                            binfo = tk.Label(rres, text=f"Passenger Name: {resv.passengerName}\nSeat Number: {resv.seatNumber}\n")
                            binfo.pack()

                    seatNumber = tk.Entry(rres)
                    seatNumber.pack()

                    remove_button = tk.Button(rres, text="Cancel Reservation", command=lambda: cancel_res(seatNumber.get(),busnum))
                    remove_button.pack()

                    exB = tk.Button(rres,text="Exit",command=ex)
                    exB.pack(pady=2)

        sBnm = tk.Button(rres, text="Submit", command=lambda: canRes())
        sBnm.pack()

        exB = tk.Button(rres,text="Exit",command=ex)
        exB.pack(pady=2)

def reserveSeat(buses, reservations):
    rseat = tk.Tk()
    rseat.title("Reserve a Seat")
    height = min(rseat.winfo_reqheight(), 906)
    rseat.minsize(360, height)
    rseat.iconbitmap("bus.ico")

    def ex():
        rseat.destroy()

    def destroy_and_reserve():
        rseat.destroy()
        reserveSeat(buses, reservations)

    def clear_widgets():
        for widget in rseat.winfo_children():
            widget.destroy()

    if buses==[]:
        bnf = tk.Label(rseat, text="No Bus Currently in system!")
        bnf.pack()
    else:
        label = tk.Label(rseat, text="Available Buses:",font=(12))
        label.pack()
        for bus in buses:
            binfo = tk.Label(rseat, text=f"Bus Number: {bus.busNumber}\nSource: {bus.source}\nDestination: {bus.destination}\nAvailable Seats: {bus.availableSeats}\n")
            binfo.pack()

        label = tk.Label(rseat, text="Enter Bus Number:")
        label.pack()
        busNumber = tk.Entry(rseat)
        busNumber.pack()
        submit_button = tk.Button(rseat, text="Submit", command=lambda: reSeat())
        submit_button.pack()

        def reSeat():
            if busNumber.get().isalpha():
                err = tk.Tk()
                err.geometry("210x50")
                err.iconbitmap("err.ico")
                err.title("Error!")
                label = tk.Label(err, text="Please enter proper values..!")
                label.pack()
                okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
                okB.pack()
            else:
                bus_num = busNumber.get()
                for bus in buses:
                    if bus.busNumber == bus_num:                 
                        if bus.availableSeats > 0:
                            clear_widgets()
                            label = tk.Label(rseat, text="Selected Bus:-")
                            label.pack()
                            label = tk.Label(rseat, text=f"Bus Number: {bus.busNumber}")
                            label.pack()
                            label = tk.Label(rseat, text=f"Source: {bus.source}")
                            label.pack()
                            label = tk.Label(rseat, text=f"Destination: {bus.destination}")
                            label.pack()

                            label = tk.Label(rseat, text="Enter Passenger Name:")
                            label.pack()
                            passengerName = tk.Entry(rseat) #input("Enter passenger name: ")
                            passengerName.pack()
                            label = tk.Label(rseat, text="Enter Seat Number:")
                            label.pack()
                            seatNumber = tk.Entry(rseat) #int(input("Enter seat number: "))
                            seatNumber.pack()

                            submit_button = tk.Button(rseat, text="Submit", command=lambda: submit_res())
                            submit_button.pack()

                            def submit_res():
                                if not(is_completely_alpha(passengerName.get())) and not(seatNumber.get().isdigit()):
                                    err = tk.Tk()
                                    err.geometry("210x50")
                                    err.iconbitmap("err.ico")
                                    err.title("Error!")
                                    label = tk.Label(err, text="Please enter proper values..!")
                                    label.pack()
                                    okB = tk.Button(err, text="Ok", command=lambda: err.after(200, err.destroy))
                                    okB.pack()
                                else:
                                    resvDoesntExist = True
                                    for resv in reservations:
                                        if seatNumber.get() == resv.seatNumber:
                                            resvDoesntExist = False
                                            label = tk.Label(rseat, text="Seat already reserved!")
                                            label.pack()
                                            rseat.after(2400, label.pack_forget)
                                            
                                    if resvDoesntExist:
                                        pax_name = passengerName.get().title()
                                        seat_num = seatNumber.get()

                                        # Find the specific bus object
                                        selected_bus = next((bus for bus in buses if bus.busNumber == bus_num), None)

                                        if selected_bus:
                                            # Decrement availableSeats for the selected bus
                                            selected_bus.availableSeats -= 1

                                            # Add reservation to the reservations list
                                            reservations.append(Reservation(bus_num, pax_name, seat_num))

                                            scc = tk.Tk()
                                            width = max(scc.winfo_reqwidth(), 480)
                                            scc.minsize(width,60)
                                            scc.iconbitmap("scc.ico")
                                            scc.title("Success!")
                                            label = tk.Label(scc, text=f"Seat: {seat_num} for Passenger: {pax_name} succesfully reserved!")
                                            label.pack()
                                            def desext():
                                                scc.after(300, scc.destroy())
                                                try:
                                                    if rseat.winfo_exists():
                                                        rseat.after(600, rseat.destroy())
                                                except tk.TclError:
                                                    pass
                                            okB = tk.Button(scc, text="Ok", command=lambda: desext())
                                            okB.pack()

                                            saveRes(reservations)
                                            saveBus(buses)
                                        else:
                                            label = tk.Label(rseat, text="Error: Bus not found!")
                                            label.pack()
                                            rseat.after(1800, label.pack_forget)

                            back_button = tk.Button(rseat, text="Back",command=lambda: rseat.after(100, destroy_and_reserve))
                            back_button.pack()

                            exB = tk.Button(rseat,text="Exit",command=ex)
                            exB.pack(pady=2)
                        else:
                            label = tk.Label(rseat, text="No available seats on this bus!")
                            label.pack()
                            rseat.after(2400, label.pack_forget)

                        break

    exB = tk.Button(rseat,text="Exit",command=ex)
    exB.pack(pady=2)

# Function to display reservation information
def displayReservations(buses,reservations):
    dispRes = tk.Tk()
    dispRes.title("Reservations")
    height = min(dispRes.winfo_reqheight(), 906)
    dispRes.minsize(360, height)
    dispRes.iconbitmap("bus.ico")

    def ex(): 
        dispRes.destroy()

    def destroy_and_reserve():
        dispRes.destroy()
        displayReservations(buses, reservations)

    def resers(bNum, reservations):
            if bNum not in [resv.busNumber for resv in reservations]:
                clear_widgets()
                label = tk.Label(dispRes, text= "Reservations:-", font=(8))
                label.pack()
                label = tk.Label(dispRes, text = "No reservations found.")
                label.pack()
                back_button = tk.Button(dispRes, text="Back",command=lambda: dispRes.after(100, destroy_and_reserve))
                back_button.pack()
                exB = tk.Button(dispRes, text="Exit", command=ex)
                exB.pack(pady=2)
            else:
                clear_widgets()
                label = tk.Label(dispRes, text="Reservations:-", font=(6))
                label.pack()
                label = tk.Label(dispRes, text=f"Bus Number: {bNum}", font=(2))
                label.pack()
                for resv in reservations:
                    if resv.busNumber == bNum:
                        label = tk.Label(dispRes, text= f"Passenger Name: {resv.passengerName}\nSeat Number: {resv.seatNumber}\n")
                        label.pack()
                back_button = tk.Button(dispRes, text="Back",command=lambda: dispRes.after(100, destroy_and_reserve))
                back_button.pack()
                exB = tk.Button(dispRes, text="Exit", command=ex)
                exB.pack(pady=2)
    def clear_widgets():
        for widget in dispRes.winfo_children():
            widget.destroy()

    if not buses:
        label = tk.Label(dispRes, text="No buses currently in system! Therefore no reservations..")
        label.pack()

        exB = tk.Button(dispRes, text="Exit", command=ex)
        exB.pack(pady=2)
    elif not reservations:
                label = tk.Label(dispRes, text = "No reservations currently in the system!")
                label.pack()
                exB = tk.Button(dispRes, text="Exit", command=ex)
                exB.pack(pady=2)
    else:
        abuses=tk.Label(dispRes,text="Available Buses:", font=(6))
        abuses.pack()
        for bus in buses:
            binfo=f"Bus Number: {bus.busNumber}\nSource: {bus.source}\nDestination: {bus.destination}\nAvailable Seats: {bus.availableSeats}"
            bin=tk.Label(dispRes, text=binfo)
            bin.pack()
        label = tk.Label(dispRes, text="Enter Bus Number for Reservations:")
        label.pack()
        bNum = tk.Entry(dispRes)
        bNum.pack()
        sb = tk.Button(dispRes, text="Submit", command=lambda: resers(bNum.get(), reservations))
        sb.pack()
        exB = tk.Button(dispRes, text="Exit", command=ex)
        exB.pack(pady=2)
    

# Function to display available buses
def displayAvailableBuses(buses):
    dispB = tk.Tk()
    dispB.title("Available Buses")
    height = min(dispB.winfo_reqheight(), 906) + 20
    dispB.minsize(360, height)
    dispB.iconbitmap("bus.ico")
    def ex():
        dispB.destroy()
    if not buses:
        nb = tk.Label(dispB,text="No buses currently in the system.")
        nb.pack()

        exB = tk.Button(dispB, text="Exit", command=ex)
        exB.pack(pady=2)
    else:
        abuses=tk.Label(dispB,text="Available Buses:", font=(8))
        abuses.pack()
        for bus in buses:
            binfo=f"Bus Number: {bus.busNumber}\nSource: {bus.source}\nDestination: {bus.destination}\nAvailable Seats: {bus.availableSeats}"
            bin=tk.Label(dispB, text=binfo)
            bin.pack()
        exB = tk.Button(dispB, text="Exit", command=ex)
        exB.pack(pady=2)

# Function to save bus information to a file
def saveBus(buses):
    with open("bus_data.txt", "w") as file:
        for bus in buses:
            file.write(f"{bus.busNumber},{bus.source},{bus.destination},{bus.totalSeats},{bus.availableSeats}\n")
    saving = tk.Label(mmenu, text="Saving Bus Data..")
    saving.after(800, lambda: saving.destroy())
    saving.pack()

def loadBusData(buses):
    buses.clear()
    file_path_bus = "bus_data.txt"

    if os.path.isfile(file_path_bus):
        with open(file_path_bus, "r") as file:
            for line in file:
                tokens = line.strip().split(",")
                if len(tokens) == 5:
                    busNumber, source, destination, totalSeats, availableSeats = tokens
                    bus = Bus(busNumber, source, destination, int(totalSeats))
                    bus.availableSeats = int(availableSeats)
                    buses.append(bus)
    else:
        with open(file_path_bus, "w") as file:
            pass


def saveRes(reservations):
    with open("reservations.txt", "w") as file:
        for reservation in reservations:
            file.write(f"{reservation.busNumber},{reservation.passengerName},{reservation.seatNumber}\n")
    saving = tk.Label(mmenu, text="Saving Bus Reservation Data..")
    saving.after(800, lambda: saving.destroy())
    saving.pack()


def loadRes(reservations):
    reservations.clear()
    file_path_res="reservations.txt"
    
    if os.path.isfile(file_path_res):
        with open(file_path_res, "r") as file:
            for line in file:
                tokens = line.strip().split(",")
                if len(tokens) == 3:
                    busNumber, passengerName, seatNumber = tokens
                    reserve = Reservation(busNumber, passengerName, seatNumber)
                    reservations.append(reserve)
    else:
        with open(file_path_res, "w") as file:
            pass

def Exit(buses,reservations):
    with open("bus_data.txt", "w") as bfile:
        for bus in buses:
            bfile.write(f"{bus.busNumber},{bus.source},{bus.destination},{bus.totalSeats},{bus.availableSeats}\n")

    with open("reservations.txt", "w") as file:
        for reservation in reservations:
            file.write(f"{reservation.busNumber},{reservation.passengerName},{reservation.seatNumber}\n")

    saving = tk.Label(mmenu, text="Saving Bus Data..")
    saving.after(1200, lambda: mmenu.destroy())
    saving.pack()

def advOps(buses,reservations):
    adv = tk.Tk()
    adv.geometry("440x400")
    adv.iconbitmap("bus.ico")
    adv.title("Advanced Menu")
    advm = tk.Label(adv, text="Advanced", font=("Helvetica", 20))
    advm.pack(pady=40)
    
    saveB = tk.Button(adv, text="Save Buses", command=lambda: saveBus(buses))
    saveB.pack()
    saveB = tk.Button(adv, text="Save Reservations", command=lambda: saveRes(reservations))
    saveB.pack()
    loadB = tk.Button(adv, text="Load Buses", command=lambda: loadBusData(buses))
    loadB.pack()
    loadB = tk.Button(adv, text="Load Reservations", command=lambda: loadRes(reservations))
    loadB.pack()
    backB = tk.Button(adv, text="Back", command=adv.destroy)
    backB.pack()



loadBusData(buses) #loading bus data at startup
loadRes(reservations) #loading reservations at startup
#GUI:-
    #Window
mmenu = tk.Tk()
mlb = tk.Label(mmenu, text="Main Menu", font=("Helvetica", 20))
mlb.pack(pady=40)
mmenu.title("Bus Management System") #Window Title

#GUI Settings
mmenu.geometry("440x400")
mmenu.iconbitmap("bus.ico")

#Buttons
adbusB = tk.Button(mmenu, text="Add Bus", command=lambda: addBus(buses))
adbusB.pack()
dispABus = tk.Button(mmenu, text="Display Available Buses", command=lambda: displayAvailableBuses(buses))
dispABus.pack()
rebusB = tk.Button(mmenu, text="Remove Bus", command=lambda: removeBus(buses, reservations))
rebusB.pack()
reSeat = tk.Button(mmenu, text="Reserve Seat", command=lambda: reserveSeat(buses,reservations))
reSeat.pack()
button = tk.Button(mmenu, text="Display Reservations", command=lambda: displayReservations(buses, reservations))
button.pack()
reSeat = tk.Button(mmenu, text="Cancel Reservations", command=lambda: cancelReserve(buses,reservations))
reSeat.pack()
advanced = tk.Button(mmenu, text="Advanced", command=lambda: advOps(buses,reservations))
advanced.pack()
exitB = tk.Button(mmenu, text="Exit", command=lambda: Exit(buses,reservations))
exitB.pack()

mmenu.mainloop() #Main Menu Looping
